#include "name_pairs.h"

#include <algorithm>
#include <iostream>

void NamePairs::read_names()
{
    std::string name;
    while (std::cin >> name)
    {
        if (std::ranges::find(names, name) != names.end())
        {
            std::cout << "Duplicate name: " << name << ". Skipping.\n";
            continue;
        }
        names.push_back(name);
    }
}
