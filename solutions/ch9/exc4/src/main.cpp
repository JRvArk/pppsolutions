#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace
{

std::string detect_base(const std::string& s)
{
    if (s.size() >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        return "hexadecimal";
    }
    if (s.size() >= 2 && s[0] == '0')
    {
        return "octal";
    }
    return "decimal";
}

} // namespace

int main()
{
    std::cout << "Enter integers (decimal, 0-prefixed octal, 0x-prefixed hex). Ctrl+D to finish:\n";

    std::vector<std::pair<std::string, int>> values;
    std::string token;
    while (std::cin >> token)
    {
        try
        {
            values.emplace_back(token, std::stoi(token, nullptr, 0));
        }
        catch (...)
        {
            std::cerr << "Invalid integer: " << token << '\n';
        }
    }

    std::cout << '\n';
    for (const auto& [original, decimal] : values)
    {
        std::cout << std::left << std::setw(10) << original << std::setw(14)
                  << detect_base(original) << std::setw(14) << "converts to" << std::right
                  << std::setw(8) << decimal << "  decimal\n";
    }
}
