#include "name_pairs.h"

#include <iostream>

void NamePairs::read_ages()
{
    for (const std::string& name : names)
    {
        std::cout << "Enter age for " << name << ": ";
        double age = 0;
        std::cin >> age;
        ages.push_back(age);
    }
}
