#ifndef METHODS_OF_COMPUTATION_REVERSEINTERPOLATOR_H
#define METHODS_OF_COMPUTATION_REVERSEINTERPOLATOR_H

#include <LagrangeMethod.h>

#include "utils/IReverseInterpolator.h"

class ReverseInterpolator : public LagrangePolynom, public IReverseInterpolator {
public:
    ReverseInterpolator(double begin, double end, std::size_t points, double eps, unsigned split_count,
                        const std::function<double(double)> &func)
            : LagrangePolynom(begin, end, points, func), eps_(eps), split_count_(split_count) {}

    ~ReverseInterpolator() override = default;

    std::vector<double> GetArguments(double value, double degree) const override;

private:
    const double eps_;
    const unsigned int split_count_;

    double GetInterpolatedValue(double argument, double degree) const override {
        return LagrangePolynom::GetInterpolatedValue(argument, degree);
    };

};


#endif //METHODS_OF_COMPUTATION_REVERSEINTERPOLATOR_H
