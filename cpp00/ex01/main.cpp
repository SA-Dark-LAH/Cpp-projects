#include "PhoneBook.hpp"
#include <iostream>

std::string    my_getline()
{
    std::string str;
        std::getline(std::cin, str);

        if (std::cin.eof())
        {
            std::cout << std::endl << "Goodbye!" << '\n' ;
            exit(0);
        }
    return (str) ;
}

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        command = my_getline();
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
    }
    std::cout << "Goodbye!" << '\n';
    return 0;
}
