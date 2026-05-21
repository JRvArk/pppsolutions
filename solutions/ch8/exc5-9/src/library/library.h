#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "../book/book.h"
#include "../patron/patron.h"

#include <chrono>
#include <string>
#include <vector>

class Library
{
public:
    struct Transaction
    {
        Book book;
        Patron patron;
        std::chrono::year_month_day date{};
    };

    void add_book(const Book& book);
    void add_patron(const Patron& patron);
    void check_out(const Book& book, const Patron& patron, std::chrono::year_month_day date);

    [[nodiscard]] std::vector<std::string> patrons_with_fees() const;

private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;
};

#endif // LIBRARY_H_
