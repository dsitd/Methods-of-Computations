#ifndef METHODS_OF_COMPUTATION_ALGORITHM_H
#define METHODS_OF_COMPUTATION_ALGORITHM_H

#include "../interval.h"

#include <iostream>
#include <vector>

class algorithm {
public:
    virtual ~algorithm() = default;

    [[nodiscard]] virtual double
    solve(const std::pair<double, double> &segment, const std::vector<std::function<double(double)>> &functions,
          double epsilon) const = 0;
};


#endif //METHODS_OF_COMPUTATION_ALGORITHM_H
