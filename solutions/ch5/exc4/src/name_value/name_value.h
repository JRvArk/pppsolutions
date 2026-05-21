#ifndef NAME_VALUE_H
#define NAME_VALUE_H

#include <ostream>
#include <string>

class NameValue
{
public:
    NameValue(std::string name, int value) : name{std::move(name)}, value{value} {}
    [[nodiscard]] const std::string& get_name() const { return name; }
    [[nodiscard]] int get_value() const { return value; }

private:
    std::string name;
    int value;
};

inline std::ostream& operator<<(std::ostream& out, const NameValue& name_val)
{
    return out << name_val.get_name() << ": " << name_val.get_value();
}

#endif // NAME_VALUE_H
