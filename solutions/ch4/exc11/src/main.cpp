#include <iostream>
#include <vector>

std::vector<int> compute_all_fib_values_for_int_type()
{
    std::vector<int> fib_values{1, 1};

    while (true)
    {
        // if the sum wraps to negative, overflow has occurred
        int next_fib_value = fib_values[fib_values.size() - 1] + fib_values[fib_values.size() - 2];
        if (next_fib_value < fib_values[fib_values.size() - 1])
        {
            break;
        }
        fib_values.push_back(next_fib_value);
    }
    return fib_values;
}

void show_n_fib_values(size_t nr_of_fib_values, const std::vector<int>& fib_values)
{
    for (size_t idx = 0; idx < nr_of_fib_values; ++idx)
    {
        std::cout << fib_values[idx] << ' ';
    }
}

int main()
{
    std::cout << "How many Fibonacci values? ";
    size_t nr_of_fib_values = 0;
    std::cin >> nr_of_fib_values;
    if (!std::cin)
    {
        std::cerr << "Invalid input\n";
        return 1;
    }

    std::vector<int> fib_values = compute_all_fib_values_for_int_type();
    if (nr_of_fib_values > fib_values.size())
    {
        std::cerr << "The number of fibonacci values requested is too big\n";
        return 1;
    }
    show_n_fib_values(nr_of_fib_values, fib_values);
    std::cout << '\n';
    std::cout << "The maximum fibonacci value for int is: " << fib_values[fib_values.size() - 1]
              << '\n';
}
