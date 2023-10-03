#include "ModifiedNewtonMethod.h"

#include <iostream>

ModifiedNewtonMethod::ModifiedNewtonMethod(const Equation& equation) : algorithm(equation) {}

double ModifiedNewtonMethod::solve(const std::pair<double, double>& segment, double epsilon) const {
    double prev_approximation = segment.first;
    double current_approximation = prev_approximation - _equation.f(prev_approximation) / _equation.df(segment.first);

    while (abs(prev_approximation - current_approximation) > epsilon) {
        prev_approximation = current_approximation;
        current_approximation = prev_approximation - _equation.f(prev_approximation) / _equation.df(segment.first);
    }


    return current_approximation;
}