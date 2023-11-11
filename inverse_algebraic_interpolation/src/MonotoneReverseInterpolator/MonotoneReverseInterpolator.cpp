#include "MonotoneReverseInterpolator.h"

void MonotoneReverseInterpolator::InvertTable() {
    for (auto &pair: this->interpolation_table_) {
        std::swap(pair.first, pair.second);
    }
}

std::vector<double> MonotoneReverseInterpolator::GetArguments(double functionValue, int degree) const {
    return {1, GetInterpolatedValue(functionValue, degree)};
}