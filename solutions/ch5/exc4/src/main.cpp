#include "./name_value/name_value.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cin.exceptions(std::ios::failbit);
    std::vector<NameValue> name_values;

    while (true)
    {
        try
        {
            std::string name;
            int value = 0;
            std::cout << "Enter name and value: ";
            std::cin >> name >> value;

            if (name == "NoName" && value == 0)
            {
                break;
            }

            bool is_duplicate = std::ranges::any_of(name_values, [&name](const NameValue& entry)
                                                    { return entry.get_name() == name; });
            if (is_duplicate)
            {
                std::cerr << "Duplicate name: " << name << '\n';
                continue;
            }

            name_values.emplace_back(name, value);
        }
        catch (const std::exception& err)
        {
            std::cerr << "Input error: " << err.what() << '\n';
            return 1;
        }
    }

    for (const NameValue& entry : name_values)
    {
        std::cout << entry << '\n';
    }

    while (true)
    {
        try
        {
            std::cout << "Enter a value to look up (or -1 to exit): ";
            int query = 0;
            std::cin >> query;
            if (query == -1)
            {
                break;
            }

            bool found = false;
            for (const NameValue& entry : name_values)
            {
                if (entry.get_value() == query)
                {
                    std::cout << entry.get_name() << '\n';
                    found = true;
                }
            }
            if (!found)
            {
                std::cout << "Value not found\n";
            }
        }
        catch (const std::exception& err)
        {
            std::cerr << "Input error: " << err.what() << '\n';
            return 1;
        }
    }
}
