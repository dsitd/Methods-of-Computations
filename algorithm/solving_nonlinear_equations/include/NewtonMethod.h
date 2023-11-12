#ifndef METHODS_OF_COMPUTATION_NEWTONMETHOD_H
#define METHODS_OF_COMPUTATION_NEWTONMETHOD_H

#include "utils/algorithm.h"

class NewtonMethod : public algorithm {
public:
    ~NewtonMethod() override = default;

    [[nodiscard]] double
    solve(const std::pair<double, double> &segment, const std::vector<std::function<double(double)>> &functions,
          double epsilon) const override;
};


#endif //METHODS_OF_COMPUTATION_NEWTONMETHOD_H
