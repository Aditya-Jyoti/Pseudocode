#include "Tests.hpp"

#include "LexerTestcases.hpp"

#include "../lexer/Lexer.hpp"
#include "../tokens/Token.hpp"

#include <cstdio>
#include <iostream>
#include <string>

namespace Tests {

// check tests for lexer
void lexerTests() {
  std::cout << "LEXER TESTS" << std::endl;
  for (int i = 0; i < static_cast<int>(LexerTestcases.size()); i++) {

    std::pair<std::string, std::vector<Token>> pair = LexerTestcases[i];

    Lexer lexer(pair.first);
    std::vector<Token> tokenizedVector = lexer.tokenize();
    std::vector<Token> actualVector = pair.second;

    for (int j = 0; j < static_cast<int>(tokenizedVector.size()); j++) {
      bool equal = tokenizedVector[j] == actualVector[j];

      if (equal) {
        std::printf("Test %d Subtest %d: Passed\n", i, j);
      } else {
        std::printf("\nTest %d Subtest %d: Failed\n", i, j);
        std::cout << "Expected: " << actualVector[j].literal << " "
                  << actualVector[j].type
                  << " Got: " << tokenizedVector[j].literal << " "
                  << tokenizedVector[j].type << "\n\n";
      }
    }
    std::cout << "\n";
  }
}

} // namespace Tests
