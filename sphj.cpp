#include <cmath>
#include "specfun.hpp"

std::pair<std::vector<double>, std::vector<double> > sphj_array(const unsigned int n, const double x) {
    std::vector<double> js(n+1, 0.0), dots(n+1, 0.0);

    if (x == 0) {
        js[0] = 1.0;
        if (n > 0)
            dots[1] = 1.0/3.0;
        return std::make_pair(js, dots);
    }

    js[0] = sin(x)/x;
    dots[0] = cos(x)-js[0]/x;

    if (n == 0)
        return std::make_pair(js, dots);

    js[1] = (js[0]-cos(x))/x;

    for (int k(2); k <= n; ++k)
        js[k] = (2*n-1)*js[k-1]/x - js[k-2];
    for (int k(1); k <= n; ++k)
        dots[k] = js[k-1] - (k+1)*js[k]/x;

    return std::make_pair(js, dots);
}
