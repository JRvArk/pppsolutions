#ifndef PATRON_H_
#define PATRON_H_

#include <string>

class Patron
{
public:
    Patron(const std::string& name, int card_number);
    Patron(const std::string& name, int card_number, double fees);

    [[nodiscard]] const std::string& get_name() const;
    [[nodiscard]] int get_card_number() const;
    [[nodiscard]] double get_fees() const;
    [[nodiscard]] bool owes_fee() const;

    void set_fees(double fees);

private:
    std::string name;
    int card_number;
    double fees;
};

#endif // PATRON_H_
