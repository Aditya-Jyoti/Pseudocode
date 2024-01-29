#include "Main.hpp"

#include <iostream>
#include <string>

#include "settings.hpp"


int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << "usage: pseudo [file].pdc" << std::endl;
    } else if (argc == 2) {
        // run pseudocode file
    } else {
        // run pseudocode in repl mode
        std::cout << "Pseudocode" << " " << VERSION << "\n";
        std::cout << DESCRIPTION << "\n";
        std::cout << "Author: " << AUTHOR << "\n" << std::endl;

        std::cout << ">>> ";

        std::string input;
        while (getline(std::cin, input)) {
            std::cout << input << "\n";
            
            if (input == "exit" || input == "quit") {
                break;
            }

            std::cout << ">>> ";
        }
        
    }
}
