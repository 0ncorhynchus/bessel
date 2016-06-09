#include <cmath>
#include <limits>
#include "specfun.hpp"

const double inf = std::numeric_limits<double>::infinity();

std::pair<std::vector<double>, std::vector<double> > sphy_array(const unsigned int n, const double x) {
    std::vector<double> ys(n+1, -inf), dots(n+1, inf);

    if (x == 0) {
        return std::make_pair(ys, dots);
    }

    ys[0] = -cos(x)/x;
    dots[0] = (sin(x)-ys[0])/x;

    if (n == 0)
        return std::make_pair(ys, dots);

    ys[1] = (ys[0]-sin(x))/x;

    for (int k(2); k <= n; ++k)
        ys[k] = (2*k-1)*ys[k-1]/x - ys[k-2];
    for (int k(1); k <= n; ++k)
        dots[k] = ys[k-1] - (k+1)*ys[k]/x;

    return std::make_pair(ys, dots);
}
