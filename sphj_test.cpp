#include "specfun.hpp"
#include <iostream>

int main() {
    int n = 1;
    for (double x(0); x < 10; x+=0.1) {
        std::pair<std::vector<double>, std::vector<double> > j(sphj_array(n, x));
        std::cout << x << ", "
            << j.first.at(n) << ", "
            << j.second.at(n) << std::endl;
    }
}

