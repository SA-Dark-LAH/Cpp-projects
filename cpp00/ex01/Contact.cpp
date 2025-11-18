#include "Contact.hpp"

int onlySpaces(std::string  str)
{
    int i = 0 ;
    while(str[i])
    {
        if(str[i] != ' ')
            return (0) ;
        i++;
    }
    return (1) ;
}

void    checker(std::string element, std::string &name)
{
    std::string answer;
    if(onlySpaces(name) || name.empty())
    {
        std::cout << "WARNING : only spaces or empty \"" << element << "\"!\n| continue ? | ('NO' / AnyInput means 'YES' - we won't warn you again)" << std::endl ;
        answer = my_getline();
        if(answer == "NO")
        {
            std::cout << "Enter " << element << " : " ;
            name = my_getline();
        } 
    }
}
void Contact::setContact()
{
    std::cout << "Enter first name: ";
    firstName = my_getline();
    checker("first name", firstName);
    
    std::cout << "Enter last name: ";
    lastName = my_getline();
    checker("last name", lastName);


    std::cout << "Enter nickname: ";
    nickname = my_getline();
    checker("nickname", nickname);

    std::cout << "Enter phone number: ";
    phoneNumber = my_getline();
    checker("phone number", phoneNumber);

    std::cout << "Enter darkest secret: ";
    darkestSecret = my_getline();
    checker("darkest secret", darkestSecret);
}

void Contact::displayFull()
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string max_chars(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayShort(int index)
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << max_chars(firstName) << "|"
              << std::setw(10) << max_chars(lastName) << "|"
              << std::setw(10) << max_chars(nickname) << std::endl;
}