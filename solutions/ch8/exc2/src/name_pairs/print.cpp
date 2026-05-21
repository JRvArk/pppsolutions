#include "name_pairs.h"

#include <iostream>

void NamePairs::print() const
{
    for (size_t idx = 0; idx < names.size(); ++idx)
    {
        std::cout << '(' << names[idx] << ", " << ages[idx] << ")\n";
    }
}
