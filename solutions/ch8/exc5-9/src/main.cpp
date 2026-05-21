#include "book/book.h"
#include "library/library.h"
#include "patron/patron.h"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main()
{
    Library lib;

    // Add books
    Book b1{"The Hobbit", "J.R.R. Tolkien", "0-04-823147-5", std::chrono::year{1937},
            Book::Genre::FICTION};
    Book b2{"A Brief History", "Stephen Hawking", "0-55-315330-X", std::chrono::year{1988},
            Book::Genre::NONFICTION};
    Book b3{"National Geo Mar", "Various", "0-02-713456-1", std::chrono::year{2023},
            Book::Genre::PERIODICAL};

    lib.add_book(b1);
    lib.add_book(b2);
    lib.add_book(b3);

    // Add patrons
    Patron p1{"Alice", 1};
    Patron p2{"Bob", 2, 5.50}; // Bob owes fees
    Patron p3{"Charlie", 3};

    lib.add_patron(p1);
    lib.add_patron(p2);
    lib.add_patron(p3);

    // Print books
    std::cout << "=== Books ===\n";
    std::cout << b1 << '\n';
    std::cout << b2 << '\n';
    std::cout << b3 << '\n';

    // Successful checkout
    std::cout << "=== Checkouts ===\n";
    try
    {
        auto date = std::chrono::year_month_day{std::chrono::year{2026}, std::chrono::month{5},
                                                std::chrono::day{22}};
        lib.check_out(b1, p1, date);
        std::cout << "Alice checked out \"" << b1.get_title() << "\"\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // Bob owes fees — should fail
    try
    {
        auto date = std::chrono::year_month_day{std::chrono::year{2026}, std::chrono::month{5},
                                                std::chrono::day{22}};
        lib.check_out(b2, p2, date);
        std::cout << "Bob checked out \"" << b2.get_title() << "\"\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // Book not in library — should fail
    try
    {
        Book unknown{"Unknown Book", "Unknown", "9-99-999999-X", std::chrono::year{2000},
                     Book::Genre::FICTION};
        auto date = std::chrono::year_month_day{std::chrono::year{2026}, std::chrono::month{5},
                                                std::chrono::day{22}};
        lib.check_out(unknown, p3, date);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // Patrons who owe fees
    std::cout << "\n=== Patrons with fees ===\n";
    std::vector<std::string> debtors = lib.patrons_with_fees();
    if (debtors.empty())
    {
        std::cout << "None\n";
    }
    else
    {
        for (const std::string& name : debtors)
        {
            std::cout << name << '\n';
        }
    }
}
