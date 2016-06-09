#ifndef __SPHJ_HPP
#define __SPHJ_HPP

#include <utility>
#include <vector>

std::pair<std::vector<double>, std::vector<double> > sphj_array(const unsigned int n, const double x);
std::pair<std::vector<double>, std::vector<double> > sphy_array(const unsigned int n, const double x);

#endif /* __SPHJ_HPP */
