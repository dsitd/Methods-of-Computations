#include <BisectionMethod.h>

double BisectionMethod::solve(const std::pair<double, double> &segment,
                              const std::vector<std::function<double(double)>> &functions, double epsilon) const {
    double left = segment.first, right = segment.second;
    unsigned int steps = 0;

    while (right - left > epsilon) {
        double middle = left + (right - left) / 2;

        if (functions[0](left) * functions[0](middle) <= 0) {
            right = middle;
        } else {
            left = middle;
        }

        steps++;
    }

    return left + (right - left) / 2;
}