#include <iostream>
#include <cctype>

int main (int ac, char **av)
{
    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for(int j = 1 ; j < ac ; j++)
    {
        std::string text = av[j];
        for(std::size_t i = 0 ; i < text.length() ; i++)
            std::cout << (char)toupper(text[i]) ;
    }
    std::cout << std::endl ;
    return (0);
}