#include <iostream>
#include <string>

enum SpelledNumbersToFour
{
    ZERO  = 0,
    ONE   = 1,
    TWO   = 2,
    THREE = 3,
    FOUR  = 4
};

int main()
{

    std::cin.exceptions(std::ios::failbit);
    std::string input;

    try
    {
        std::cin >> input;
    }
    catch (const std::ios_base::failure&)
    {
        std::cerr << "Error: expected a string.\n";
        return 1;
    }

    SpelledNumbersToFour number;

    if (input == "zero" || input == "0")
    {
        number = SpelledNumbersToFour::ZERO;
    }
    else if (input == "one" || input == "1")
    {
        number = SpelledNumbersToFour::ONE;
    }
    else if (input == "two" || input == "2")
    {
        number = SpelledNumbersToFour::TWO;
    }
    else if (input == "three" || input == "3")
    {
        number = SpelledNumbersToFour::THREE;
    }
    else if (input == "four" || input == "4")
    {
        number = SpelledNumbersToFour::FOUR;
    }
    else
    {
        std::cerr << "not a number I know.\n";
        return 1;
    }

    std::cout << number << '\n';
}
