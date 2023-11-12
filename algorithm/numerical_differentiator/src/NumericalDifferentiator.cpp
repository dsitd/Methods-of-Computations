#include "NumericalDifferentiator.h"

std::vector<std::array<double, 6>> NumericalDifferentiator::SearchDerivative() const {
    std::vector<std::array<double, 6>> result;
    std::size_t index = 0;

    for (const auto &[x, y]: interpolation_table_) {
        double first_derivative = CalculateFirstDerivative(index);
        double first_derivative_error = abs(first_derivative - functions_[1](x));

        double second_derivative = CalculateSecondDerivative(index);
        double second_derivative_error = abs(second_derivative - functions_[2](x));

        result.push_back({
                                 x,
                                 y,
                                 first_derivative,
                                 first_derivative_error,
                                 second_derivative,
                                 second_derivative_error
                         });

        index++;
    }

    return result;
}

double NumericalDifferentiator::CalculateFirstDerivative(std::size_t ind) const {
    if (ind == 0) {
        return (-3 * interpolation_table_[ind].second + 4 * interpolation_table_[ind + 1].second -
                interpolation_table_[ind + 2].second)
               / (2 * step_);
    } else if (ind == interpolation_table_.size()) {
        return (3 * interpolation_table_[ind].second - 4 * interpolation_table_[ind - 1].second +
                interpolation_table_[ind - 2].second)
               / (2 * step_);
    }

    return (interpolation_table_[ind + 1].second - interpolation_table_[ind - 1].second) / (2 * step_);
}

double NumericalDifferentiator::CalculateSecondDerivative(std::size_t ind) const {
    return (interpolation_table_[ind + 1].second - 2 * interpolation_table_[ind].second +
            interpolation_table_[ind - 1].second)
           / (step_ * step_);
}
