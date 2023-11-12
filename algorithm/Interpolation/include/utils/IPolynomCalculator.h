#ifndef METHODS_OF_COMPUTATION_IPOLYNOMCALCULATOR_H
#define METHODS_OF_COMPUTATION_IPOLYNOMCALCULATOR_H

class IPolynomCalculator {
public:
    [[nodiscard]] virtual double GetInterpolatedValue(double argument, double degree) const = 0;

    virtual ~IPolynomCalculator() = default;
};

#endif //METHODS_OF_COMPUTATION_IPOLYNOMCALCULATOR_H
