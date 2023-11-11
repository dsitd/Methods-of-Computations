#ifndef METHODS_OF_COMPUTATION_MONOTONEREVERSEINTERPOLATOR_H
#define METHODS_OF_COMPUTATION_MONOTONEREVERSEINTERPOLATOR_H

#include "../../../algebraic_interpolation/src/algorithm/NewtonMethod/NewtonMethod.h"
#include "../IReverseInterpolator.h"

class MonotoneReverseInterpolator : public NewtonPolynom, public IReverseInterpolator {
private:
    void InvertTable();

    [[nodiscard]] double GetInterpolatedValue(double argument, double degree) const override { return NewtonPolynom::GetInterpolatedValue(argument, degree); };
public:
    MonotoneReverseInterpolator(double begin, double end, int numPoints, const std::function<double(double)>& func)
            : NewtonPolynom(begin, end, numPoints, func) {
        InvertTable();
    };

    [[nodiscard]] std::vector<double> GetArguments(double functionValue, int degree) const override;
};


#endif //METHODS_OF_COMPUTATION_MONOTONEREVERSEINTERPOLATOR_H
