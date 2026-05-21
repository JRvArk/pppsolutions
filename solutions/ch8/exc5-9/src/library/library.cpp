#include "library.h"

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{

auto find_book(std::vector<Book>& books, const Book& book)
{
    return std::ranges::find_if(books,
                                [&](const Book& b) { return b.get_isbn() == book.get_isbn(); });
}

auto find_patron(std::vector<Patron>& patrons, const Patron& patron)
{
    return std::ranges::find_if(patrons, [&](const Patron& p)
                                { return p.get_card_number() == patron.get_card_number(); });
}

} // namespace

void Library::add_book(const Book& book)
{
    if (find_book(books, book) != books.end())
    {
        throw std::runtime_error("Book already in library");
    }
    books.push_back(book);
}

void Library::add_patron(const Patron& patron)
{
    if (find_patron(patrons, patron) != patrons.end())
    {
        throw std::runtime_error("Patron already in library");
    }
    patrons.push_back(patron);
}

void Library::check_out(const Book& book, const Patron& patron, std::chrono::year_month_day date)
{
    auto book_it = find_book(books, book);
    if (book_it == books.end())
    {
        throw std::runtime_error("Book not found in library");
    }

    auto patron_it = find_patron(patrons, patron);
    if (patron_it == patrons.end())
    {
        throw std::runtime_error("Patron not found in library");
    }

    if (patron_it->owes_fee())
    {
        throw std::runtime_error("Patron owes fees and cannot check out books");
    }

    book_it->check_out();
    transactions.push_back({.book = *book_it, .patron = *patron_it, .date = date});
}

std::vector<std::string> Library::patrons_with_fees() const
{
    std::vector<std::string> result;
    for (const Patron& p : patrons)
    {
        if (p.owes_fee())
        {
            result.push_back(p.get_name());
        }
    }
    return result;
}
