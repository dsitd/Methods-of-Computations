#ifndef METHODS_OF_COMPUTATION_MODIFIEDNEWTONMETHOD_H
#define METHODS_OF_COMPUTATION_MODIFIEDNEWTONMETHOD_H

#include "../algorithm.h"


class ModifiedNewtonMethod : public algorithm {
public:
    ModifiedNewtonMethod(const Equation &equation);
    ~ModifiedNewtonMethod() override = default;
    [[nodiscard]] double solve(const std::pair<double, double>& segment, double epsilon) const override;
};


#endif //METHODS_OF_COMPUTATION_MODIFIEDNEWTONMETHOD_H
