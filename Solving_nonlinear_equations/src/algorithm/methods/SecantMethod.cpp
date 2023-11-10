#include "SecantMethod.h"

SecantMethod::SecantMethod(const Equation &equation) : algorithm(equation) {}

double SecantMethod::solve(const std::pair<double, double> &segment, double epsilon) const {
    double prev_prev_approximation = segment.first;
    double prev_approximation = segment.second;
    unsigned int steps = 0;

    double current_approximation = prev_approximation - _equation.f(prev_approximation) /
                                                        (_equation.f(prev_approximation) -
                                                         _equation.f(prev_prev_approximation)) *
                                                        (prev_approximation - prev_prev_approximation);

    while (abs(prev_approximation - current_approximation) > epsilon) {
        prev_prev_approximation = prev_approximation;
        prev_approximation = current_approximation;
        current_approximation = prev_approximation - _equation.f(prev_approximation) /
                                                     (_equation.f(prev_approximation) -
                                                      _equation.f(prev_prev_approximation)) *
                                                     (prev_approximation - prev_prev_approximation);
        steps++;
    }

    std::cout << "number of steps: " << steps << std::endl;

    return current_approximation;
}