#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cin.exceptions(std::ios::failbit);
    std::vector<std::string> names;
    std::vector<int> scores;

    while (true)
    {
        try
        {
            std::string name;
            int score = 0;
            std::cout << "Enter name and score: ";
            std::cin >> name >> score;

            if (name == "NoName" && score == 0)
            {
                break;
            }
            bool is_duplicate = false;
            for (const std::string& n : names)
            {
                if (n == name)
                {
                    is_duplicate = true;
                    break;
                }
            }
            if (is_duplicate)
            {
                std::cerr << "Duplicate name: " << name << '\n';
                return 1;
            }

            names.push_back(name);
            scores.push_back(score);
        }
        catch (const std::ios_base::failure&)
        {
            std::cerr << "Input error: expected a name and an integer.\n";
            return 1;
        }
    }

    while (true)
    {
        std::cout << "Enter a name to look up (or NoName to exit): ";
        std::string query;
        std::cin >> query;
        if (query == "NoName")
        {
            break;
        }

        bool found = false;
        for (size_t i = 0; i < names.size(); ++i)
        {
            if (names[i] == query)
            {
                std::cout << query << ": " << scores[i] << '\n';
                found = true;
                break;
            }
        }
        if (!found)
        {
            std::cout << "name not found\n";
        }
    }
}