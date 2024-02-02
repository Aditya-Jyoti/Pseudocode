#include "Lexer.hpp"

#include <string>
#include <vector>

#include "../tokens/Token.hpp"
#include "../tokens/TokenType.hpp"

// move positions to the next buffer
void Lexer::next() { this->currPosition = this->nextPosition++; }

// check if current character is a set of characters
void Lexer::handleWords(const std::string &word) {
  Token token;
  token.literal = word;

  // check if the input word exists in map
  if (MultipleCharacterMap.find(word) != MultipleCharacterMap.end()) {
    token.type = MultipleCharacterMap[word];
  }
  // input word does not exist, most likely an identifier
  else {
    token.type = TokenType::IDENTIFIER;
  }

  this->tokens.push_back(token);
}

// check if double character exists
bool Lexer::handleDoubleCharacters(const std::string &characters) {
  Token token;

  // double character exists
  if (DoubleCharacterMap.find(characters) != DoubleCharacterMap.end()) {
    token.type = DoubleCharacterMap[characters];
    token.literal = characters;

    this->tokens.push_back(token);

    return true;
  }
  // double character does not exist as legal characters
  else {
    return false;
  }
}

// check if character is legal or not
void Lexer::handleSingleCharacter(const std::string &character) {
  Token token;
  token.literal = character;

  // character is legal
  if (SingleCharacterMap.find(character) != SingleCharacterMap.end()) {
    token.type = SingleCharacterMap[character];
  }
  // single character is illegal
  else {
    token.type = TokenType::ILLEGAL;
  }

  this->tokens.push_back(token);
}

// convert characters to tokens and return a vector
std::vector<Token> Lexer::tokenize() {

  while (this->currPosition < static_cast<int>(this->input.length())) {

    // check if the next position overflows
    if (this->nextPosition >= static_cast<int>(this->input.length())) {
      this->nextChar = '\0'; // EOF Character
    }

    this->currChar = this->input[this->currPosition];
    this->nextChar = this->input[this->nextPosition];

    // ignore all whitespace characters
    if (std::isspace(this->currChar)) {
      this->next();

      continue;
    }

    // check if current character is a set of characters
    if (std::isalpha(this->currChar)) {
      std::string currWord = std::string(1, this->currChar);

      // add characters to a word as long as the next character is alpha
      while (std::isalpha(this->nextChar)) {
        currWord += std::string(1, this->nextChar);

        this->nextPosition++;
        this->nextChar = this->input[this->nextPosition];
      }

      this->handleWords(currWord);
      this->next();

      continue;
    }

    // check if current double characters is legal double character
    if (this->nextChar == '=' || this->nextChar == '+' ||
        this->nextChar == '-') {

      std::string currWord = std::string(1, this->currChar) + this->nextChar;

      // if double character exists, move next position one forward to
      // to offset current position
      if (this->handleDoubleCharacters(currWord)) {
        this->nextPosition++;
        this->next();
        continue;
      }
    }

    // check if single characters are legal or not
    this->handleSingleCharacter(std::string(1, this->currChar));
    this->next();
  }

  return this->tokens;
}
