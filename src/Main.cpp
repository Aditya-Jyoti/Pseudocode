#include <cstring>
#include <iostream>
#include <string>

#include "settings.hpp"

#include "lexer/Lexer.hpp"
#include "tests/Tests.hpp"
#include "tokens/Token.hpp"

int main(int argc, char *argv[]) {
  if (!std::strcmp(argv[1], "test")) {
    Tests::lexerTests();
    return 0;
  }

  if (argc > 2) {
    std::cout << "usage: pseudo [file].pdc" << std::endl;
  } else if (argc == 2) {
    // run pseudocode file
  } else {
    // run pseudocode in repl mode
    std::cout << "Pseudocode"
              << " " << VERSION << "\n";
    std::cout << DESCRIPTION << "\n";
    std::cout << "Author: " << AUTHOR << "\n" << std::endl;

    std::cout << ">>> ";

    std::string input;
    while (getline(std::cin, input)) {
      std::cout << input << "\n";

      if (input == "exit" || input == "quit") {
        break;
      }

      Lexer lexer(input);

      for (Token token : lexer.tokenize()) {
        std::cout << token.literal << "\n";
      }

      std::cout << ">>> ";
    }
  }
}
