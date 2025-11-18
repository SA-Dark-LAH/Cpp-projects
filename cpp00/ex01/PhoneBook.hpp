#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <stdlib.h>

class PhoneBook
{
private:
    Contact contacts[8];
    int total;
    int oldestIndex;

public:
    PhoneBook();
    void addContact();
    void searchContact();
};
std::string    my_getline();

#endif
