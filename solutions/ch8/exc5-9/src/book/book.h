#ifndef BOOK_H_
#define BOOK_H_

#include <chrono>
#include <iosfwd>
#include <string>

class Book
{
public:
    enum class Genre
    {
        FICTION,
        NONFICTION,
        PERIODICAL,
        BIOGRAPHY,
        CHILDREN
    };

    Book();
    Book(const std::string& title, const std::string& author, const std::string& isbn,
         std::chrono::year copyright_date, Genre genre);
    Book(const std::string& title, const std::string& author, const std::string& isbn,
         std::chrono::year copyright_date, Genre genre, bool checked_out);

    void check_in();
    void check_out();

    [[nodiscard]] const std::string& get_title() const;
    [[nodiscard]] const std::string& get_author() const;
    [[nodiscard]] const std::string& get_isbn() const;
    [[nodiscard]] std::chrono::year get_copyright_date() const;
    [[nodiscard]] Genre get_genre() const;
    [[nodiscard]] bool is_checked_out() const;

    void set_title(const std::string& title);
    void set_author(const std::string& author);
    void set_isbn(const std::string& isbn);
    void set_copyright_date(std::chrono::year copyright_date);
    void set_genre(Genre genre);

private:
    std::string title;
    std::string author;
    std::string isbn;
    std::chrono::year copyright_date;
    Genre genre;
    bool checked_out;
};

bool operator==(const Book& lhs, const Book& rhs);
bool operator!=(const Book& lhs, const Book& rhs);
std::ostream& operator<<(std::ostream& out, const Book& book);

#endif // BOOK_H_
