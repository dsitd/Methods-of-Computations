#ifndef METHODS_OF_COMPUTATION_BISECTIONMETHOD_H
#define METHODS_OF_COMPUTATION_BISECTIONMETHOD_H

#include "../algorithm.h"

class BisectionMethod : public algorithm {

public:
    ~BisectionMethod() override = default;

    [[nodiscard]] double
    solve(const std::pair<double, double> &segment, const std::vector<std::function<double(double)>> &functions,
          double epsilon) const override;
};


#endif //METHODS_OF_COMPUTATION_BISECTIONMETHOD_H
