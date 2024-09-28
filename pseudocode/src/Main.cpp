#include "Main.hpp"

/* Main class implementation
TODO: Implement - pseudocode interpreter
TODO: Implement - interactive mode
*/

int Main::run(int argc, char *argv[])
{
    if (argc > 2)
    {
        std::cout << "Usage: pseudo [script.pseu]" << std::endl;
        return 0;
    }
    else if (argc == 2)
    {
        std::cout << "Running script: " << argv[1] << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Running interactive mode" << std::endl;
        return 1;
    }
}

int main(int argc, char *argv[])
{
    return Main::run(argc, argv);
}
