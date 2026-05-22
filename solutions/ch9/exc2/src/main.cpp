#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string file_name;
    std::string word;

    std::cout << "Enter the name of the file: ";
    std::cin >> file_name;

    std::cout << "Enter the word to search for: ";
    std::cin >> word;

    std::ifstream file(file_name);

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << file_name << '\n';
        return 1;
    }

    std::string line;
    std::istringstream iss;
    std::string token;
    for (size_t line_num = 1; std::getline(file, line); ++line_num)
    {
        iss.clear();
        iss.str(line);
        while (iss >> token)
        {
            if (token == word)
            {
                std::cout << "Line " << line_num << ": " << line << '\n';
                break;
            }
        }
    }
}
