#ifndef METHODS_OF_COMPUTATION_SECANTMETHOD_H
#define METHODS_OF_COMPUTATION_SECANTMETHOD_H

#include "../algorithm.h"

class SecantMethod : public algorithm {
public:
    SecantMethod(const Equation &equation);
    ~SecantMethod() override = default;
    [[nodiscard]] double solve(const std::pair<double, double>& segment, double epsilon) const override;
};


#endif //METHODS_OF_COMPUTATION_SECANTMETHOD_H
