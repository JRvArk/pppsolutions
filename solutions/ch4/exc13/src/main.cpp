#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    int seed{};
    std::cout << "Enter a seed: ";
    std::cin >> seed;

    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(0, 9);
    while (true)
    {
        std::vector<int> answer;
        while (answer.size() < 4)
        {
            int digit = dist(rng);
            if (std::ranges::find(answer, digit) == answer.end())
            {
                answer.push_back(digit);
            }
        }

        while (true)
        {
            std::cout << "Enter your guess: ";
            std::vector<int> guess(4);
            for (int& gues : guess)
            {
                char ch{};
                std::cin >> ch;
                if (!std::cin || ch < '0' || ch > '9')
                {
                    std::cerr << "Invalid input\n";
                    return 1;
                }
                gues = ch - '0';
            }

            int bulls = 0;
            int cows  = 0;
            for (size_t i = 0; i < guess.size(); ++i)
            {
                if (guess[i] == answer[i])
                {
                    ++bulls;
                }
                else
                {
                    auto pos = std::ranges::find(answer, guess[i]);
                    if (pos != answer.end() &&
                        guess[pos - answer.begin()] != answer[pos - answer.begin()])
                    {
                        ++cows;
                    }
                }
            }

            if (bulls == 4)
            {
                std::cout << "Congratulations! You've guessed the number!\n";
                break;
            }
            std::cout << "Bulls: " << bulls << ", Cows: " << cows << '\n';
        }

        std::cout << "Play again? (y/n): ";
        char again{};
        std::cin >> again;
        if (again != 'y' && again != 'Y')
        {
            break;
        }
    }
}
