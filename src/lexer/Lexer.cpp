#include "Lexer.hpp"

#include <cctype>
#include <string>
#include <vector>

#include "../tokens/Token.hpp"
#include "../tokens/TokenType.hpp"
#include "../utility/Error.hpp"

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

  // character is legal
  if (SingleCharacterMap.find(character) != SingleCharacterMap.end()) {
    Token token;
    token.literal = character;
    token.type = SingleCharacterMap[character];
    this->tokens.push_back(token);
  }
  // single character is illegal
  else {
    Error("Syntax", this->rowNumber, this->currPosition,
          "Illegal character: " + character + " not recognized by intepreter");
    this->hasError = true;
    return;
  }
}

// check if characters are enclosed in quotes
bool Lexer::handleStrings(const char &quote) {

  std::string currString;

  while (this->nextChar != quote) {

    // ending quote not found on current line
    if (this->nextPosition >= static_cast<int>(this->input.length())) {
      Error("Syntax", this->rowNumber, this->nextPosition,
            "Could not find ending quote: " + std::string(1, quote));
      this->hasError = true;
      return false;
    }

    // add character to string and move forward
    currString += std::string(1, this->nextChar);
    this->nextPosition++;
    this->nextChar = this->input[this->nextPosition];
  }

  // character enclosed in quote
  Token token;
  token.type = TokenType::STRING;
  token.literal = currString;

  this->tokens.push_back(token);
  return true;
}

// check if characters are a number (integer or decimal)
bool Lexer::handleNumbers() {
  std::string currNumber;
  bool hasDecimalPoint = false;

  currNumber += std::string(1, this->currChar);

  // check if character is a number (has decimal or not)
  while (std::isdigit(this->nextChar) || this->nextChar == '.') {

    if (this->nextChar == '.') {
      if (hasDecimalPoint) {
        Error("Syntax", this->rowNumber, this->nextPosition,
              "Can not use more than a single decimal point in a number");
        this->hasError = true;
        return false;

      } else {

        hasDecimalPoint = true;
      }
    }

    // add character to string and move forward
    currNumber += std::string(1, this->nextChar);
    this->nextPosition++;
    this->nextChar = this->input[this->nextPosition];
  }

  Token token;

  // if legal decimal points then its a decimal num
  if (hasDecimalPoint) {
    token.type = TokenType::DECIMAL;
  } else {
    token.type = TokenType::INTEGER;
  }

  token.literal = currNumber;

  this->tokens.push_back(token);

  return true;
}

// convert characters to tokens and return a vector
std::vector<Token> Lexer::tokenize() {

  while (this->currPosition < static_cast<int>(this->input.length())) {
    this->currChar = this->input[this->currPosition];
    this->nextChar = this->input[this->nextPosition];
    
    // TODO: Handle do and end statements
    if (this->input[this->input.length() - 1] != ';') {
        Error("Syntax", this->rowNumber, this->input.length(), "Expected ';' after expression");

        this->hasError = true;
        this->tokens.clear();
        return this->tokens;
    }

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

    // check if current char is a quote and hence sequence is a
    // string or not
    if (this->currChar == '\"' || this->currChar == '\'') {
      if (this->handleStrings(this->currChar)) {

        this->nextPosition++;
        this->next();

        continue;
      } else {

        this->nextPosition = this->currPosition + 1;
      }
    }

    // check if current char is a digit and hence sequence is a
    // number or not
    if (std::isdigit(this->currChar)) {
      if (this->handleNumbers()) {
        this->next();

        continue;
      } else {
        this->nextPosition = this->currPosition + 1;
        this->nextChar = this->input[this->nextPosition];
      }
    }

    // check if single characters are legal or not
    this->handleSingleCharacter(std::string(1, this->currChar));
    this->next();
  }

  return this->tokens;
}
