#include <iostream>

int main()
{
    std::cout << "Please provide an integer: ";

    int val = 0;

    std::cin.exceptions(std::ios::failbit);
    try
    {
        std::cin >> val;
    }
    catch (const std::ios_base::failure&)
    {
        std::cerr << "Error: expected an integer.\n";
        return 1;
    }

    if (val % 2 == 0)
    {
        std::cout << val << " is an even number.\n";
    }
    else
    {
        std::cout << val << " is an odd number.\n";
    }
}
