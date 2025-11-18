#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    std::string level = av[1];
    Harl harl;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4 && level != levels[i])
        i++;

    switch (i) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO"); 
        case 2:
            harl.complain("WARNING"); 
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}