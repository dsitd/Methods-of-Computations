#include <iostream>
#include <memory>
#include <vector>

#include "src/equation.h"
#include "src/interval.h"
#include "src/algorithm/methods/BisectionMethod.h"
#include "src/algorithm/methods/NewtonMethod.h"
#include "src/algorithm/methods/ModifiedNewtonMethod.h"
#include "src/algorithm/methods/SecantMethod.h"

double epsilon = pow(10, -8);
double left_border, right_border;
int32_t amount_splitting;

void searchRoot(const Equation &equation,const std::vector<std::pair<double, double>>& segments) {
    std::unique_ptr<algorithm> algorithm;

    std::cout << "--------------" << std::endl;
    algorithm = std::make_unique<BisectionMethod>(equation);
    std::cout << "BisectionMethod: " << std::endl;
    for (auto &segment : segments) {
        std::cout << "segment: [" << segment.first << "; " << segment.second << "] | root: " << algorithm->solve(segment, epsilon) << std::endl;
    }

    std::cout << "--------------" << std::endl;
    algorithm = std::make_unique<NewtonMethod>(equation);
    std::cout << "NewtonMethod: " << std::endl;
    for (auto &segment : segments) {
        std::cout << "segment: [" << segment.first << "; " << segment.second << "] | root: " << algorithm->solve(segment, epsilon) << std::endl;
    }

    std::cout << "--------------" << std::endl;
    algorithm = std::make_unique<ModifiedNewtonMethod>(equation);
    std::cout << "ModifiedNewtonMethod: " << std::endl;
    for (auto &segment : segments) {
        std::cout << "segment: [" << segment.first << "; " << segment.second << "] | root: " << algorithm->solve(segment, epsilon) << std::endl;
    }

    std::cout << "--------------" << std::endl;
    algorithm = std::make_unique<SecantMethod>(equation);
    std::cout << "SecantMethod: " << std::endl;
    for (auto &segment : segments) {
        std::cout << "segment: [" << segment.first << "; " << segment.second << "] | root: " << algorithm->solve(segment, epsilon) << std::endl;
    }
}

int main() {
    std::cout << "Enter the interval: ";
    std::cin >> left_border >> right_border;

    std::cout << "Enter the split: ";
    std::cin >> amount_splitting;

    Equation equation;
    Interval interval(left_border, right_border, amount_splitting, equation);
    std::vector<std::pair<double, double>> segments = interval.getSegment();

    std::cout << "Initial data:" << std::endl
    << "equation: " << equation._f << std::endl
    << "Interval: [" << interval.getLeftBorder() << "; " << interval.getRightBorder() << ']' << std::endl
    << "epsilon: " << epsilon << std::endl;

    searchRoot(equation, segments);

    return 0;
}
