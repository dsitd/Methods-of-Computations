#ifndef METHODS_OF_COMPUTATION_LAGRANGEMETHOD_H
#define METHODS_OF_COMPUTATION_LAGRANGEMETHOD_H

#include "../../InterpolationCalculator/InterpolationCalculator.h"
#include "../IPolynomCalculator.h"

class LagrangePolynom : public InterpolationCalculator, public IPolynomCalculator {
private:
    static double CalculateFundamentalPoly(double argument, double point, Table const &sorted_interpolation_table);

public:
    LagrangePolynom(double begin, double end, int numPoints, const std::function<double(double)> &func)
            : InterpolationCalculator(begin, end, numPoints, func) {}

    ~LagrangePolynom() override = default;

    [[nodiscard]] double GetInterpolatedValue(double argument, double degree) const override;
};

#endif //METHODS_OF_COMPUTATION_LAGRANGEMETHOD_H
