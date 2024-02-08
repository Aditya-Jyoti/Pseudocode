#ifndef LEXER_TESTCASES
#define LEXER_TESTCASES

#include "../tokens/Token.hpp"
#include "../tokens/TokenType.hpp"

#include <string>
#include <vector>

const std::vector<std::pair<std::string, std::vector<Token>>> LexerTestcases = {
    // Single character tokens
    {"{([;:,.])}",
     {
         {"{", TokenType::LEFT_BRACE},
         {"(", TokenType::LEFT_PARENTHESIS},
         {"[", TokenType::LEFT_BRACKET},
         {";", TokenType::SEMICOLON},
         {":", TokenType::COLON},
         {",", TokenType::COMMA},
         {".", TokenType::DOT},
         {"]", TokenType::RIGHT_BRACKET},
         {")", TokenType::RIGHT_PARENTHESIS},
         {"}", TokenType::RIGHT_BRACE},
     }},

    // Arithmetic
    {"+-/=%*",
     {{"+", TokenType::PLUS},
      {"-", TokenType::MINUS},
      {"/", TokenType::DIVIDE},
      {"=", TokenType::ASSIGNMENT},
      {"%", TokenType::MODULO},
      {"*", TokenType::STAR}}},

    // Assignment
    {"=+=-=++--",
     {
         {"=", TokenType::ASSIGNMENT},
         {"+=", TokenType::PLUS_EQUAL},
         {"-=", TokenType::MINUS_EQUAL},
         {"++", TokenType::PLUS_PLUS},
         {"--", TokenType::MINUS_MINUS},
     }},

    // Comparison
    {"!====>>=<<=",
     {
         {"!=", TokenType::BANG_EQUAL},
         {"==", TokenType::EQUAL_EQUAL},
         {"=", TokenType::ASSIGNMENT},
         {">", TokenType::GREATER},
         {">=", TokenType::GREATER_EQUAL},
         {"<", TokenType::LESSER},
         {"<=", TokenType::LESSER_EQUAL},
     }},

    // Boolean logic
    {"!&|",
     {
         {"!", TokenType::LOGICAL_NOT},
         {"&", TokenType::LOGICAL_AND},
         {"|", TokenType::LOGICAL_OR},
     }},

    // Keywords
    {"define hello do end",
     {
         {"define", TokenType::DEFINE},
         {"hello", TokenType::IDENTIFIER},
         {"do", TokenType::DO},
         {"end", TokenType::END},
     }},

    // datatypes
    // // string
    {"\"test1\" \'test2\'",
     {
         {"test1", TokenType::STRING},
         {"test2", TokenType::STRING},
     }},

    {"12 12.3",
     {
         {"12", TokenType::INTEGER},
         {"12.3", TokenType::DECIMAL},
     }},

};

#endif
