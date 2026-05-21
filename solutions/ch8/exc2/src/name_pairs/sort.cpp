#include "name_pairs.h"

#include <algorithm>
#include <cctype>
#include <string>

void NamePairs::sort()
{
    for (size_t pass = 0; pass < names.size(); ++pass)
    {
        bool swapped = false;
        for (size_t idx = 0; idx < names.size() - 1; ++idx)
        {
            std::string lower_current = names[idx];
            std::string lower_next    = names[idx + 1];
            std::ranges::transform(lower_current, lower_current.begin(), ::tolower);
            std::ranges::transform(lower_next, lower_next.begin(), ::tolower);
            if (lower_current > lower_next)
            {
                std::swap(names[idx], names[idx + 1]);
                std::swap(ages[idx], ages[idx + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
