#include <cmath>
#include "specfun.hpp"

inline double sphj0(const double x) { return sin(x)/x; }

std::pair<double*, double*> sphj_array(const int n, const double x) {
    double* sj = new double[n];
    double* dj = new double[n];

    if (x == 0) {
        for (int k(0); k < n; ++k) {
            sj[k] = dj[k] = 0.0;
        }
        sj[0] = 1.0;
        if (n > 0)
            dj[1] = 1.0/3.0;

        return std::pair<double*, double*>(sj, dj);
    }

    sj[0] = sphj0(x);
    dj[0] = (cos(x)-sj[0])/x;

    if (n == 0)
        return std::pair<double*, double*>(sj, dj);

    sj[1] = (sj[0]-cos(x))/x;

    for (int k(2); k < n; ++k) {
        sj[k] = (2*n+1)*sj[k-1]/x - sj[k-2];
    }
    for (int k(1); k < n; ++k) {
        dj[k] = sj[k-1] - (k+1)*sj[k]/x;
    }

    return std::pair<double*, double*>(sj, dj);
}
