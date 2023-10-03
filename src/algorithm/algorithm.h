#ifndef METHODS_OF_COMPUTATION_ALGORITHM_H
#define METHODS_OF_COMPUTATION_ALGORITHM_H

#include "../equation.h"
#include "../interval.h"

class algorithm {
protected:
    Equation _equation;

public:
    explicit algorithm(const Equation& equation) : _equation(equation) {}
    virtual ~algorithm() = default;
    [[nodiscard]] virtual double solve(const std::pair<double, double>& segment, double epsilon) const = 0;
};


#endif //METHODS_OF_COMPUTATION_ALGORITHM_H
