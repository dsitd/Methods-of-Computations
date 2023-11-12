#include "SecantMethod.h"

double SecantMethod::solve(const std::pair<double, double> &segment,
                           const std::vector<std::function<double(double)>> &functions, double epsilon) const {
    double prev_prev_approximation = segment.first;
    double prev_approximation = segment.second;
    unsigned int steps = 0;

    double current_approximation = prev_approximation - functions[0](prev_approximation) /
                                                        (functions[0](prev_approximation) -
                                                         functions[0](prev_prev_approximation)) *
                                                        (prev_approximation - prev_prev_approximation);

    while (abs(prev_approximation - current_approximation) > epsilon) {
        prev_prev_approximation = prev_approximation;
        prev_approximation = current_approximation;
        current_approximation = prev_approximation - functions[0](prev_approximation) /
                                                     (functions[0](prev_approximation) -
                                                      functions[0](prev_prev_approximation)) *
                                                     (prev_approximation - prev_prev_approximation);
        steps++;
    }

    return current_approximation;
}