#ifndef METHODS_OF_COMPUTATION_LAGRANGEMETHOD_H
#define METHODS_OF_COMPUTATION_LAGRANGEMETHOD_H

#include <utils/IPolynomCalculator.h>
#include <utils/InterpolationCalculator.h>

class LagrangePolynom : public InterpolationCalculator, public IPolynomCalculator {
private:
    static double CalculateFundamentalPoly(double argument, double point, Table const &sorted_interpolation_table);

public:
    LagrangePolynom(double begin, double end, std::size_t points, const std::function<double(double)> &func)
            : InterpolationCalculator(begin, end, points, func) {}

    ~LagrangePolynom() override = default;

    [[nodiscard]] double GetInterpolatedValue(double argument, double degree) const override;
};

#endif //METHODS_OF_COMPUTATION_LAGRANGEMETHOD_H
