#include "name_pairs/name_pairs.h"

#include <iostream>
#include <sstream>

int main()
{
    NamePairs np;

    std::istringstream names_input{"Alice Bob Charlie Alice Dave"};
    std::cin.rdbuf(names_input.rdbuf());
    np.read_names();

    std::istringstream ages_input{"30 25 35 28"};
    std::cin.rdbuf(ages_input.rdbuf());
    np.read_ages();

    std::cout << "Before sort:\n";
    np.print();

    np.sort();

    std::cout << "\nAfter sort:\n";
    np.print();
}
