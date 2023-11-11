#ifndef METHODS_OF_COMPUTATION_REVERSEINTERPOLATOR_H
#define METHODS_OF_COMPUTATION_REVERSEINTERPOLATOR_H

#include "../../../algebraic_interpolation/src/algorithm/LagrangeMethod/LagrangeMethod.h"
#include "../IReverseInterpolator.h"


class ReverseInterpolator : public LagrangePolynom, public IReverseInterpolator {
private:
    double const eps;
    int const splitCount;

    double GetInterpolatedValue(double argument, double degree) const override {
        return LagrangePolynom::GetInterpolatedValue(argument, degree);
    };

public:
    ReverseInterpolator(double begin, double end, int numPoints, double eps, int splitCount, const std::function<double(double)>& func)
            : LagrangePolynom(begin, end, numPoints, func), eps(eps), splitCount(splitCount) {}

    std::vector<double> getArguments(double functionValue, int degree) const;
};


#endif //METHODS_OF_COMPUTATION_REVERSEINTERPOLATOR_H
