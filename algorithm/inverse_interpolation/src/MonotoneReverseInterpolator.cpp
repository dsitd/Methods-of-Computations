#include "../include/MonotoneReverseInterpolator.h"

void MonotoneReverseInterpolator::InvertTable() {
    for (auto &pair: this->interpolation_table_) {
        std::swap(pair.first, pair.second);
    }
}

std::vector<double> MonotoneReverseInterpolator::GetArguments(double value, double degree) const {
    return {1, GetInterpolatedValue(value, degree)};
}