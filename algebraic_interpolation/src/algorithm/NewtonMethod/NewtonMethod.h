#ifndef METHODS_OF_COMPUTATION_NEWTONMETHOD_H
#define METHODS_OF_COMPUTATION_NEWTONMETHOD_H

#include "../../InterpolationCalculator/InterpolationCalculator.h"
#include "../IPolynomCalculator.h"

class NewtonPolynom : public InterpolationCalculator, public IPolynomCalculator {
private:
    static std::vector<double> CreateDividedDiffTable(Table const &sorted_interpolation_table);

public:
    NewtonPolynom(double begin, double end, std::size_t points, const std::function<double(double)> &func)
            : InterpolationCalculator(begin, end, points, func) {}

    ~NewtonPolynom() override = default;

    [[nodiscard]] double GetInterpolatedValue(double argument, double degree) const override;
};


#endif //METHODS_OF_COMPUTATION_NEWTONMETHOD_H
