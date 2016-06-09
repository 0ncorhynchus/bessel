#include "specfun.hpp"
#include <cstdlib>
#include <iostream>

typedef std::pair<std::vector<double>, std::vector<double> > values;

int main(int argc, char** argv) {
    int n(0);
    if (argc > 1)
        n = std::atoi(argv[1]);

    for (double x(0); x < 10; x += 0.1) {
        values j(sphj_array(n, x));
        values y(sphy_array(n, x));
        std::cout << x << ", "
            << j.first.at(n) << ", "
            << j.second.at(n) << ", "
            << y.first.at(n) << ", "
            << y.second.at(n) << std::endl;
    }
}
