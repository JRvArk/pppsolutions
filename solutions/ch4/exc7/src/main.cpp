#include <cmath>
#include <iostream>
#include <stdexcept>

void print_roots(double a, double b, double c)
{
    if (a == 0.0)
    {
        throw std::invalid_argument("coefficient a must not be zero");
    }

    double discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0)
    {
        throw std::domain_error("no real roots (negative discriminant)");
    }

    double disc_sqrt = std::sqrt(discriminant);
    double root1     = (-b + disc_sqrt) / (2 * a);
    double root2     = (-b - disc_sqrt) / (2 * a);

    constexpr double EPSILON = 1e-9;

    if (std::abs(root1 - root2) < EPSILON)
    {
        std::cout << "One real root: " << root1 << '\n';
        std::cout << "Verification: "
                  << (std::abs((a * root1 * root1) + (b * root1) + c) < EPSILON ? "pass" : "fail")
                  << '\n';
    }
    else
    {
        std::cout << "Two real roots: " << root1 << " and " << root2 << '\n';
        std::cout << "Verification: root1 "
                  << (std::abs((a * root1 * root1) + (b * root1) + c) < EPSILON ? "pass" : "fail")
                  << ", root2 "
                  << (std::abs((a * root2 * root2) + (b * root2) + c) < EPSILON ? "pass" : "fail")
                  << '\n';
    }
}

int main()
{
    std::cin.exceptions(std::ios::failbit);

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    try
    {
        std::cout << "Enter coefficients a, b, c: ";
        std::cin >> a >> b >> c;
    }
    catch (const std::ios_base::failure&)
    {
        std::cerr << "Input error: expected three numbers.\n";
        return 1;
    }

    try
    {
        print_roots(a, b, c);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}