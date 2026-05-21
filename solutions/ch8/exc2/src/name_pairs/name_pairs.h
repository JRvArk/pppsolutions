#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H

#include <string>
#include <vector>

class NamePairs
{
public:
    void read_names();
    void read_ages();
    void print() const;
    void sort();

private:
    std::vector<std::string> names;
    std::vector<double> ages;
};

#endif // NAME_PAIRS_H