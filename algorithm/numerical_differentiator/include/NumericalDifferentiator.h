#ifndef METHODS_OF_COMPUTATION_NUMERICALDIFFERENTIATOR_H
#define METHODS_OF_COMPUTATION_NUMERICALDIFFERENTIATOR_H

#include <utils/InterpolationCalculator.h>

#include <vector>
#include <ostream>
#include <functional>

class NumericalDifferentiator : public InterpolationCalculator {
public:
    using Function = std::function<double(double)>;

    NumericalDifferentiator(double begin, double step, std::size_t step_count, const std::vector<Function> functions)
            : InterpolationCalculator(begin, begin + step * step_count, step_count + 1, functions[0]), step_(step),
              functions_(functions) {
    }

    std::vector<std::array<double, 6>> SearchDerivative() const;

private:
    double CalculateFirstDerivative(std::size_t ind) const;

    double CalculateSecondDerivative(std::size_t ind) const;

    std::vector<std::function<double(double)>> functions_;
    double step_;
};


#endif //METHODS_OF_COMPUTATION_NUMERICALDIFFERENTIATOR_H
