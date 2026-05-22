#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string filename;
    std::cout << "Enter the input filename: ";
    std::cin >> filename;

    std::ifstream input_file(filename);
    if (!input_file.is_open())
    {
        std::cerr << "Error opening input file: " << filename << '\n';
        return 1;
    }

    std::string output_filename;
    std::cout << "Enter the output filename: ";
    std::cin >> output_filename;

    std::ofstream output_file(output_filename);
    if (!output_file.is_open())
    {
        std::cerr << "Error opening output file: " << output_filename << '\n';
        return 1;
    }

    constexpr std::string_view VOWELS = "aeiouAEIOU";
    std::string line;
    while (std::getline(input_file, line))
    {
        for (char ch : line)
        {
            if (VOWELS.find(ch) == std::string_view::npos)
            {
                output_file << ch;
            }
        }
        output_file << '\n';
    }
}
