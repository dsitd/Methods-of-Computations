#ifndef METHODS_OF_COMPUTATION_INTERPOLATIONALCALCULATOR_H
#define METHODS_OF_COMPUTATION_INTERPOLATIONALCALCULATOR_H

#include <vector>
#include <functional>
#include <iostream>

class InterpolationCalculator {
public:
    using Table = std::vector<std::pair<double, double>>;

    void PrintTable(std::ostream &output) const;

protected:
    InterpolationCalculator(double begin, double end, std::size_t points, const std::function<double(double)> &func);

    void GenerateInterpolationTable(double begin, double end);

    [[nodiscard]] Table CreateSortedInterpolationTable(double argument, double degree) const;

    std::vector<std::pair<double, double>> interpolation_table_;
    std::function<double(double)> func_;

    std::size_t points_;
};


#endif //METHODS_OF_COMPUTATION_INTERPOLATIONALCALCULATOR_H
