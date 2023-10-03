#include "NewtonMethod.h"

NewtonMethod::NewtonMethod(const Equation& equation) : algorithm(equation) {}


double NewtonMethod::solve(const std::pair<double, double>& segment, double epsilon) const {
    double prev_approximation = segment.first;
    double current_approximation =
            prev_approximation - _equation.f(prev_approximation) / _equation.df(prev_approximation);

    while (abs(prev_approximation - current_approximation) > epsilon) {
        prev_approximation = current_approximation;
        current_approximation =
                prev_approximation - _equation.f(prev_approximation) / _equation.df(prev_approximation);
    }

    return current_approximation;
}