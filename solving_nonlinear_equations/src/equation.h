#ifndef METHODS_OF_COMPUTATION_EQUATION_H
#define METHODS_OF_COMPUTATION_EQUATION_H

#include <cmath>
#include <string>

class Equation {
public:
    std::string _f = "sqrt(4 * x + 7) - 3 * cos(x)";
    std::string _df = "3 * sin(x) + 2 / (sqrt(4 * x + 7))";

    static double f(double x) {
        return sqrt(4 * x + 7) - 3 * cos(x);
    }

    static double df(double x) {
        return 3 * sin(x) + 2 / (sqrt(4 * x + 7));
    }
};

#endif //METHODS_OF_COMPUTATION_EQUATION_H
