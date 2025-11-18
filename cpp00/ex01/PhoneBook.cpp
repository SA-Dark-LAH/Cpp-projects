#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    total = 0;
    oldestIndex = 0;
}

void PhoneBook::addContact()
{
    contacts[oldestIndex].setContact(); 
    oldestIndex = (oldestIndex + 1) % 8;
    if (total < 8)
        total++;
}

void PhoneBook::searchContact()
{
    if (total == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"                 
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < total; i++)
        contacts[i].displayShort(i + 1);

    std::cout << "Enter the index of the contact to view: ";
    std::string input;
    input = my_getline();

    if (input.length() != 1 || input[0] < '1' || input[0] > ('0' + total))
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = input[0] - '1';
    contacts[index].displayFull();
}
