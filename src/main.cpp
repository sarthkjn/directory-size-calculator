#include <iostream>
#include <string>
#include "FileSystem.h"

int main() {
    FileSystem fs;
    std::string command;

    std::cout << "Welcome to the Directory Size Calculator CLI.\n";
    std::cout << "Commands: ls, cd <dir>, cd .., size, exit\n";

    while (true) {
        fs.printCurrentPath();  // e.g., "root > "
        std::getline(std::cin, command);

        if (command == "ls") {
            fs.listDirectory();
        }
        else if (command == "size") {
            fs.showSize();
        }
        else if (command == "exit") {
            break;
        }
        else if (command.substr(0, 3) == "cd ") {
            std::string dirname = command.substr(3);
            fs.changeDirectory(dirname);
        }
        else {
            std::cout << "Unknown command. Try: ls, cd <dir>, cd .., size, exit\n";
        }
    }

    std::cout << "Exiting. Goodbye!\n";
    return 0;
}
