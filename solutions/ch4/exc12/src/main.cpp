#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> answer{4, 2, 5, 8};

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
        for (size_t idx = 0; idx < guess.size(); ++idx)
        {
            if (guess[idx] == answer[idx])
            {
                ++bulls;
            }
            else
            {
                auto pos = std::ranges::find(answer, guess[idx]);
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
}
