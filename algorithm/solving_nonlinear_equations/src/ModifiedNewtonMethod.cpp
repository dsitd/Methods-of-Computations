#include <ModifiedNewtonMethod.h>

double ModifiedNewtonMethod::solve(const std::pair<double, double> &segment,
                                   const std::vector<std::function<double(double)>> &functions, double epsilon) const {
    double prev_approximation = segment.first;
    double current_approximation = prev_approximation - functions[0](prev_approximation) / functions[1](segment.first);
    unsigned int steps = 0;

    while (abs(prev_approximation - current_approximation) > epsilon) {
        prev_approximation = current_approximation;
        current_approximation = prev_approximation - functions[0](prev_approximation) / functions[1](segment.first);
        steps++;
    }

    return current_approximation;
}