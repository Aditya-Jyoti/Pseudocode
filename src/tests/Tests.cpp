#include "Tests.hpp"

#include "LexerTestcases.hpp"

#include "../lexer/Lexer.hpp"
#include "../tokens/Token.hpp"

#include <cstdio>
#include <iostream>
#include <string>

namespace Tests {

template <typename Tester>
bool assert_equal(const Tester &LHS, const Tester &RHS) {
  if (LHS == RHS) {
    return true;
  }
  return false;
}

// check tests for lexer
void lexerTests() {
  for (int i = 0; i < LexerTestcases.size(); i++) {
    std::pair<std::string, std::vector<Token>> pair = LexerTestcases[i];

    Lexer lexer(pair.first);
    std::vector<Token> tokenizedVector = lexer.tokenize();
    std::vector<Token> actualVector = pair.second;

    for (int j = 0; j < tokenizedVector.size(); j++) {
      bool equal = Tests::assert_equal(tokenizedVector[j], actualVector[j]);

      if (equal) {
        std::printf("Test %d Subtest %d: Passed\n", i, j);
      } else {
        std::printf("\nTest %d Subtest %d: Failed\n", i, j);
        std::cout << "Expected: " << actualVector[j].literal
                  << " Got: " << tokenizedVector[j].literal << "\n\n";
      }
    }
  }
}

} // namespace Tests
