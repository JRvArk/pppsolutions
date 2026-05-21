#include "./functions.h"

#include <iostream>

void print(const std::string& label, const std::vector<int>& values)
{
    std::cout << label << ": ";
    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}