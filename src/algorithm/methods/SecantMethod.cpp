#include "SecantMethod.h"

SecantMethod::SecantMethod(const Equation& equation) : algorithm(equation) {}

double SecantMethod::solve(const std::pair<double, double>& segment, double epsilon) const {
    double pre_prev_approximation = segment.first;
    double prev_approximation = segment.second;

    double currentApproximation = prev_approximation - _equation.f(prev_approximation) / (_equation.f(prev_approximation) - _equation.f(pre_prev_approximation)) * (prev_approximation - pre_prev_approximation);

    while (abs(prev_approximation - currentApproximation) > epsilon) {
        pre_prev_approximation = prev_approximation;
        prev_approximation = currentApproximation;
        currentApproximation = prev_approximation - _equation.f(prev_approximation) / (_equation.f(prev_approximation) - _equation.f(pre_prev_approximation)) * (prev_approximation - pre_prev_approximation);
    }

    return currentApproximation;
}