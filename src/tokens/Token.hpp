#ifndef TOKENS
#define TOKENS

#include "TokenType.hpp"

#include <string>

struct Token {
  std::string literal;
  TokenType type;

  Token() = default;
  Token(std::string literal, TokenType type) : literal(literal), type(type) {}

  bool operator==(const Token &RHS) const { return this->type == RHS.type && this->literal == RHS.literal; }
};

#endif
