#include "utils/InterpolationCalculator.h"

InterpolationCalculator::InterpolationCalculator(double begin, double end, std::size_t points,
                                                 const std::function<double(double)> &func)
        : func_(func), points_(points) {
    this->GenerateInterpolationTable(begin, end);
}

InterpolationCalculator::Table
InterpolationCalculator::CreateSortedInterpolationTable(double argument, double degree) const {
    Table sorted_interpolation_table = this->interpolation_table_;

    std::sort(sorted_interpolation_table.begin(), sorted_interpolation_table.end(),
              [argument](std::pair<double, double> pair1, std::pair<double, double> pair2) {
                  return abs(pair1.first - argument) < abs(pair2.first - argument);
              });

    sorted_interpolation_table.resize(static_cast<std::size_t>(degree));
    return sorted_interpolation_table;
}

void InterpolationCalculator::GenerateInterpolationTable(double begin, double end) {
    double step = (end - begin) / static_cast<double>(points_);

    interpolation_table_.reserve(points_);

    for (int i = 0; i + 1 < points_; i++) {
        double x = begin + i * step;
        interpolation_table_.emplace_back(x, func_(x));
    }

    interpolation_table_.emplace_back(end, func_(end));
}


void InterpolationCalculator::PrintTable(std::ostream &output) const {
    output << "x:\t\t\t\t\t\t| func(x):\n";
    for (auto const &pair: interpolation_table_) {
        output << pair.first << "\t| " << pair.second << '\n';
    }
}
