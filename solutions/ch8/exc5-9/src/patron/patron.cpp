#include "patron.h"

#include <stdexcept>
#include <string>

namespace
{

void validate_name(const std::string& name)
{
    if (name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
}

void validate_card_number(int card_number)
{
    if (card_number <= 0)
    {
        throw std::invalid_argument("Card number must be positive");
    }
}

void validate_fees(double fees)
{
    if (fees < 0.0)
    {
        throw std::invalid_argument("Fees cannot be negative");
    }
}

} // namespace

Patron::Patron(const std::string& name, int card_number)
    : name{name}, card_number{card_number}, fees{0.0}
{
    validate_name(name);
    validate_card_number(card_number);
}

Patron::Patron(const std::string& name, int card_number, double fees)
    : name{name}, card_number{card_number}, fees{fees}
{
    validate_name(name);
    validate_card_number(card_number);
    validate_fees(fees);
}

const std::string& Patron::get_name() const
{
    return name;
}
int Patron::get_card_number() const
{
    return card_number;
}
double Patron::get_fees() const
{
    return fees;
}
bool Patron::owes_fee() const
{
    return fees > 0.0;
}

void Patron::set_fees(double fees)
{
    validate_fees(fees);
    this->fees = fees;
}
