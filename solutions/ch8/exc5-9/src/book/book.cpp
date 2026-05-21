#include "book.h"

#include <cctype>
#include <chrono>
#include <ostream>
#include <stdexcept>
#include <string>

namespace
{

constexpr std::chrono::year MIN_COPYRIGHT_YEAR{0};

std::chrono::year max_copyright_year()
{
    return std::chrono::year_month_day{
        std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())}
        .year();
}

void validate_title(const std::string& title)
{
    if (title.empty())
    {
        throw std::invalid_argument("Title cannot be empty");
    }
}

void validate_author(const std::string& author)
{
    if (author.empty())
    {
        throw std::invalid_argument("Author cannot be empty");
    }
}

void validate_isbn(const std::string& isbn)
{
    // expected format: n-n-n-x where n is one or more digits, x is a digit or letter
    const auto INVALID = []() { throw std::invalid_argument("ISBN must be of the form n-n-n-x"); };

    std::string::size_type pos = 0;
    for (int group = 0; group < 3; ++group)
    {
        auto dash = isbn.find('-', pos);
        if (dash == std::string::npos)
        {
            INVALID();
        }
        if (dash == pos)
        {
            INVALID();
        }
        for (auto i = pos; i < dash; ++i)
        {
            if (std::isdigit(static_cast<unsigned char>(isbn[i])) == 0)
            {
                INVALID();
            }
        }
        pos = dash + 1;
    }

    if (pos >= isbn.size() || isbn.find('-', pos) != std::string::npos)
    {
        INVALID();
    }
    if ((std::isdigit(static_cast<unsigned char>(isbn[pos])) == 0) &&
        (std::isalpha(static_cast<unsigned char>(isbn[pos])) == 0))
    {
        INVALID();
    }
    if (isbn.size() - pos != 1)
    {
        INVALID();
    }
}

void validate_copyright_date(std::chrono::year year)
{
    if (year < MIN_COPYRIGHT_YEAR || year > max_copyright_year())
    {
        throw std::invalid_argument("Invalid copyright date");
    }
}

void validate_all(const std::string& title, const std::string& author, const std::string& isbn,
                  std::chrono::year copyright_date)
{
    validate_title(title);
    validate_author(author);
    validate_isbn(isbn);
    validate_copyright_date(copyright_date);
}

std::string genre_to_string(Book::Genre genre)
{
    switch (genre)
    {
    case Book::Genre::FICTION:
        return "Fiction";
    case Book::Genre::NONFICTION:
        return "Nonfiction";
    case Book::Genre::PERIODICAL:
        return "Periodical";
    case Book::Genre::BIOGRAPHY:
        return "Biography";
    case Book::Genre::CHILDREN:
        return "Children";
    }
    return "Unknown";
}

} // namespace

Book::Book() : copyright_date{0}, genre{Genre::FICTION}, checked_out{false}
{
    validate_copyright_date(copyright_date);
}

Book::Book(const std::string& title, const std::string& author, const std::string& isbn,
           std::chrono::year copyright_date, Genre genre)
    : title{title}, author{author}, isbn{isbn}, copyright_date{copyright_date}, genre{genre},
      checked_out{false}
{
    validate_all(title, author, isbn, copyright_date);
}

Book::Book(const std::string& title, const std::string& author, const std::string& isbn,
           std::chrono::year copyright_date, Genre genre, bool checked_out)
    : title{title}, author{author}, isbn{isbn}, copyright_date{copyright_date}, genre{genre},
      checked_out{checked_out}
{
    validate_all(title, author, isbn, copyright_date);
}

void Book::check_in()
{
    checked_out = false;
}
void Book::check_out()
{
    checked_out = true;
}

const std::string& Book::get_title() const
{
    return title;
}
const std::string& Book::get_author() const
{
    return author;
}
const std::string& Book::get_isbn() const
{
    return isbn;
}
std::chrono::year Book::get_copyright_date() const
{
    return copyright_date;
}
Book::Genre Book::get_genre() const
{
    return genre;
}
bool Book::is_checked_out() const
{
    return checked_out;
}

void Book::set_title(const std::string& title)
{
    validate_title(title);
    this->title = title;
}

void Book::set_author(const std::string& author)
{
    validate_author(author);
    this->author = author;
}

void Book::set_isbn(const std::string& isbn)
{
    validate_isbn(isbn);
    this->isbn = isbn;
}

void Book::set_copyright_date(std::chrono::year copyright_date)
{
    validate_copyright_date(copyright_date);
    this->copyright_date = copyright_date;
}

void Book::set_genre(Genre genre)
{
    this->genre = genre;
}

bool operator==(const Book& lhs, const Book& rhs)
{
    return lhs.get_isbn() == rhs.get_isbn();
}

bool operator!=(const Book& lhs, const Book& rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
    return out << book.get_title() << '\n'
               << book.get_author() << '\n'
               << book.get_isbn() << '\n'
               << genre_to_string(book.get_genre()) << '\n';
}
