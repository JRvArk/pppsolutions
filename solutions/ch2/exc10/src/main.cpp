#include <iostream>
#include <string>

enum class Operation
{
    PLUS,
    MINUS,
    MUL,
    DIV
};

int main()
{
    std::cin.exceptions(std::ios::failbit);
    std::string input;
    double left  = 0.0;
    double right = 0.0;

    try
    {
        std::cin >> input >> left >> right;
    }
    catch (const std::ios_base::failure&)
    {
        std::cerr << "Error: expected a string followed by two doubles.\n";
        return 1;
    }

    Operation op;
    if (input == "+" || input == "plus")
    {
        op = Operation::PLUS;
    }
    else if (input == "-" || input == "minus")
    {
        op = Operation::MINUS;
    }
    else if (input == "*" || input == "mul")
    {
        op = Operation::MUL;
    }
    else if (input == "/" || input == "div")
    {
        op = Operation::DIV;
    }
    else
    {
        std::cerr << "Error: unknown operation '" << input << "'.\n";
        return 1;
    }

    double result = 0.0;
    switch (op)
    {
    case Operation::PLUS:
        result = left + right;
        break;
    case Operation::MINUS:
        result = left - right;
        break;
    case Operation::MUL:
        result = left * right;
        break;
    case Operation::DIV:
        if (right == 0.0)
        {
            std::cerr << "Error: division by zero.\n";
            return 1;
        }
        result = left / right;
        break;
    }

    std::cout << "Result: " << result << '\n';
}