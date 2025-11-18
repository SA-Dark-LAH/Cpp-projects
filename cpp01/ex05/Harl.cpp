#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my burger.\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\n" << "Adding extra bacon costs more money.\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\n" << "I think I deserve extra bacon for free.\n" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager!\n" << std::endl;
}

void Harl::complain(std::string level) {

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*funcs[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}