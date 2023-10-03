#include "BisectionMethod.h"

BisectionMethod::BisectionMethod(const Equation& equation) : algorithm(equation) {}

double BisectionMethod::solve(const std::pair<double, double>& segment, double epsilon) const {
    double left = segment.first, right = segment.second;

    while (right - left > epsilon) {
        double middle = left + (right - left) / 2;

        if (_equation.f(left) * _equation.f(middle) <= 0) {
            right = middle;
        } else {
            left = middle;
        }
    }

    return left + (right - left) / 2;
}