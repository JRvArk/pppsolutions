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

    for (size_t i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << ": " << scores[i] << '\n';
    }

    while (true)
    {
        try
        {
            std::cout << "Enter a score to look up (or -1 to exit): ";
            int query = 0;
            std::cin >> query;
            if (query == -1)
            {
                break;
            }

            bool found = false;
            for (size_t i = 0; i < scores.size(); ++i)
            {
                if (scores[i] == query)
                {
                    std::cout << names[i] << '\n';
                    found = true;
                }
            }
            if (!found)
            {
                std::cout << "score not found\n";
            }
        }
        catch (const std::ios_base::failure&)
        {
            std::cerr << "Input error: expected an integer.\n";
            return 1;
        }
    }
}