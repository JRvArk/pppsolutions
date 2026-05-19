#include <iostream>
#include <vector>

int main()
{
    int n_sum = 0;
    std::cout << "Enter the number of first values you want to sum: ";
    std::cin.exceptions(std::ios::failbit);
    try
    {
        std::cin >> n_sum;
    }
    catch (const std::ios_base::failure&)
    {
        std::cerr << "Error: expected an integer.\n";
        return 1;
    }

    if (n_sum < 0)
    {
        std::cerr << "Error: number of values to sum must not be negative.\n";
        return 1;
    }
    if (n_sum == 0)
    {
        std::cout << "Sum of the first 0 values is: 0\n";
        return 0;
    }

    std::vector<int> values;
    std::cout << "Enter a series of integers (press '|' to stop): ";
    std::cin.exceptions(std::ios::goodbit);
    int value = 0;
    while (std::cin >> value)
    {
        values.push_back(value);
    }

    std::cin.clear();
    char sentinel = 0;
    std::cin >> sentinel;
    if (sentinel != '|')
    {
        std::cerr << "Error: unexpected character '" << sentinel << "', expected '|'.\n";
        return 1;
    }

    if (values.empty())
    {
        std::cerr << "Error: no values entered.\n";
        return 1;
    }
    if (static_cast<size_t>(n_sum) > values.size())
    {
        std::cerr << "Error: requested sum of " << n_sum << " values but only " << values.size()
                  << " were entered.\n";
        return 1;
    }

    int sum = 0;
    std::cout << "The sum of the first " << n_sum << " numbers ( ";
    for (int i = 0; i < n_sum; ++i)
    {
        std::cout << values[i] << ' ';
        sum += values[i];
    }
    std::cout << ") is " << sum << '\n';
}