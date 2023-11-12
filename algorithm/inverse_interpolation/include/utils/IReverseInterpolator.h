#ifndef METHODS_OF_COMPUTATION_IREVERSEINTERPOLATOR_H
#define METHODS_OF_COMPUTATION_IREVERSEINTERPOLATOR_H

#include <vector>

class IReverseInterpolator {
public:
    virtual std::vector<double> GetArguments(double value, double degree) const = 0;

    virtual ~IReverseInterpolator() = default;
};


#endif //METHODS_OF_COMPUTATION_IREVERSEINTERPOLATOR_H
