#ifndef METHODS_OF_COMPUTATION_MONOTONEREVERSEINTERPOLATOR_H
#define METHODS_OF_COMPUTATION_MONOTONEREVERSEINTERPOLATOR_H

#include <NewtonMethod.h>

#include "utils/IReverseInterpolator.h"

class MonotoneReverseInterpolator : public NewtonPolynom, public IReverseInterpolator {
private:
    void InvertTable();

    [[nodiscard]] double GetInterpolatedValue(double argument, double degree) const override {
        return NewtonPolynom::GetInterpolatedValue(argument, degree);
    };
public:
    MonotoneReverseInterpolator(double begin, double end, std::size_t points, const std::function<double(double)> &func)
            : NewtonPolynom(begin, end, points, func) {
        InvertTable();
    };

    [[nodiscard]] std::vector<double> GetArguments(double value, double degree) const override;
};


#endif //METHODS_OF_COMPUTATION_MONOTONEREVERSEINTERPOLATOR_H
