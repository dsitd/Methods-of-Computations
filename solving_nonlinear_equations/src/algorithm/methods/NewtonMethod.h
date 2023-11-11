#ifndef METHODS_OF_COMPUTATION_NEWTONMETHOD_H
#define METHODS_OF_COMPUTATION_NEWTONMETHOD_H

#include "../algorithm.h"

class NewtonMethod : public algorithm {
public:
    NewtonMethod(const Equation &equation);

    ~NewtonMethod() override = default;

    [[nodiscard]] double solve(const std::pair<double, double> &segment, double epsilon) const override;
};


#endif //METHODS_OF_COMPUTATION_NEWTONMETHOD_H
