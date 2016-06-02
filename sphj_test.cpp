#include "specfun.hpp"
#include <iostream>

int main() {
    int n = 1;
    for (double x(0); x < 10; x+=0.1) {
        std::pair<double*, double*> j(sphj_array(n, x));
        std::cout << x << ", "
            << j.first[n] << ", "
            << j.second[n] << std::endl;
        delete[] j.first;
        delete[] j.second;
    }
}

