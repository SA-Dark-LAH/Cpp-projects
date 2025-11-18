#include <iostream>
#include <fstream>
#include <string>

std::string replace_in_string(std::string content, const std::string &s1, const std::string &s2)
{
    size_t pos = 0;

    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    return content;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cout << "Error: cannot replace an empty string (s1).\n";
        return 1;
    }
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cout << "Error: cannot open file: " << filename << std::endl;
        return 1;
    }
    std::string content;
    std::getline(infile, content);
    infile.close();

    std::string replaced = replace_in_string(content, s1, s2);

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cout << "Error: cannot create output file.\n";
        return 1;
    }
    outfile << replaced;
    outfile.close();

    return 0;
}

