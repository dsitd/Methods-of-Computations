#ifndef METHODS_OF_COMPUTATION_INTERVAL_H
#define METHODS_OF_COMPUTATION_INTERVAL_H

#include <vector>

#include "equation.h"

class Interval {
    int32_t amount_splitting;
    double left_border, right_border;
    std::vector<std::pair<double, double>> segments;

    void separateRoots(const Equation &equation) {
        double offset = (right_border - left_border) / static_cast<double>(amount_splitting), point = left_border;
        double multiplication_border;

        while (point + offset <= right_border) {
            multiplication_border = equation.f(point) * equation.f(point + offset);

            if (multiplication_border <= 0) {
                segments.emplace_back(point, point + offset);
            }

            point += offset;
        }
    }

public:
    Interval(double left_border, double right_border, int32_t amount_splitting, const Equation &equation)
            : left_border(left_border), right_border(right_border), amount_splitting(amount_splitting) {

        if (left_border > right_border) {
            throw std::logic_error("left_border > right_border");
        }

        separateRoots(equation);
    }

    std::vector<std::pair<double, double>> getSegment() {
        return segments;
    }

    double getLeftBorder() {
        return left_border;
    }

    double getRightBorder() {
        return right_border;
    }
};


#endif //METHODS_OF_COMPUTATION_INTERVAL_H
