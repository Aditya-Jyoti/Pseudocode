#ifndef LEXER
#define LEXER

#include "../tokens/Token.hpp"

#include <string>
#include <vector>

class Lexer {
private:
  std::string input;

  int rowNumber = 0;

  int currPosition = 0;
  int nextPosition = 1;

  char currChar;
  char nextChar;

  std::vector<Token> tokens;

  void next();

  Token getToken(const std::string &input);

  bool handleStrings(const char &quote);
  bool handleNumbers();

  void handleWords(const std::string &word);

  bool handleDoubleCharacters(const std::string &characters);
  void handleSingleCharacter(const std::string &character);

public:
  Lexer() = default;
  Lexer(const std::string input) : input(input) {}

  bool hasError = false;

  std::vector<Token> tokenize();
};

#endif
