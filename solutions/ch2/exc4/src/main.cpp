#include <iostream>

int main()
{
    std::cout << "Enter two integers: ";
    int val1 = 0;
    int val2 = 0;
    std::cin >> val1 >> val2;

    std::cout << "Smaller: " << (val1 < val2 ? val1 : val2) << '\n'
              << "Larger: " << (val1 > val2 ? val1 : val2) << '\n'
              << "Sum: " << val1 + val2 << '\n'
              << "Difference: " << val1 - val2 << '\n'
              << "Product: " << val1 * val2 << '\n';

    if (val2 == 0)
    {
        std::cout << "Ratio: undefined (division by zero)\n";
    }
    else
    {
        std::cout << "Ratio: " << static_cast<double>(val1) / val2 << '\n';
    }
}
