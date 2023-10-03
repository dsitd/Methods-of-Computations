#ifndef METHODS_OF_COMPUTATION_BISECTIONMETHOD_H
#define METHODS_OF_COMPUTATION_BISECTIONMETHOD_H

#include "../algorithm.h"

class BisectionMethod : public algorithm {

public:
    explicit BisectionMethod(const Equation& equation);
    ~BisectionMethod() override = default;

    [[nodiscard]] double solve(const std::pair<double, double>& segment, double epsilon) const override;
};


#endif //METHODS_OF_COMPUTATION_BISECTIONMETHOD_H
