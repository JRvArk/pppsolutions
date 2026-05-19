#include <iostream>

int main()
{
    std::cout << "Please, enter three integers: ";
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;

    std::cin.exceptions(std::ios::failbit);
    try
    {
        std::cin >> val1 >> val2 >> val3;
    }
    catch (const std::ios_base::failure&)
    {
        std::cerr << "Error: expected three integers.\n";
        return 1;
    }

    int smallest = val1;
    if (val2 < smallest)
    {
        smallest = val2;
    }
    if (val3 < smallest)
    {
        smallest = val3;
    }

    int largest = val1;
    if (val2 > largest)
    {
        largest = val2;
    }
    if (val3 > largest)
    {
        largest = val3;
    }

    int middle = val1 + val2 + val3 - smallest - largest;

    std::cout << smallest << ", " << middle << ", " << largest << '\n';
}
