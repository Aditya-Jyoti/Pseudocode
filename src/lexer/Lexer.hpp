#ifndef LEXER
#define LEXER

#include "../tokens/Token.hpp"

#include <string>
#include <vector>

class Lexer {
private:
  std::string input;

  int currPosition = 0;
  int nextPosition = 1;

  char currChar;
  char nextChar;
  std::string currWord;

  std::vector<Token> tokens;

  void next();

  Token getToken(const std::string &input);

  void handleStrings(const char &quoteType);

  void handleCharacters();
  void handleWords();

public:
  Lexer() = default;
  Lexer(const std::string input) : input(input) {}

  std::vector<Token> tokenize();
};

#endif
