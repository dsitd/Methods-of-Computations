#include <iostream>
#include <iomanip>
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

void searchRoot(const Equation &equation, const std::vector<std::pair<double, double>> &segments) {
    std::vector<std::unique_ptr<algorithm>> algorithms(4);
    double root;

    algorithms[0] = std::make_unique<BisectionMethod>(equation);
    algorithms[1] = std::make_unique<NewtonMethod>(equation);
    algorithms[2] = std::make_unique<ModifiedNewtonMethod>(equation);
    algorithms[3] = std::make_unique<SecantMethod>(equation);

    std::cout << std::fixed << std::setprecision(15);

    for (auto &segment: segments) {
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
        std::cout << "Segment: [" << segment.first << "; " << segment.second << "]" << std::endl;
        std::cout << "BisectionMethod: " << std::endl;
        std::cout << "Initial approximation: " << segment.second - segment.first << std::endl;

        root = algorithms[0]->solve(segment, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(equation.f(root)) << std::endl;
        std::cout << "----------" << std::endl;

        std::cout << "NewtonMethod: " << std::endl;
        std::cout << "Initial approximation: "
                  << abs(segment.first - segment.first - equation.f(segment.first) / equation.df(segment.first))
                  << std::endl;
        root = algorithms[1]->solve(segment, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(equation.f(root)) << std::endl;
        std::cout << "----------" << std::endl;

        std::cout << "ModifiedNewtonMethod: " << std::endl;
        std::cout << "Initial approximation: "
                  << abs(segment.first - segment.first - equation.f(segment.first) / equation.df(segment.first))
                  << std::endl;
        root = algorithms[2]->solve(segment, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(equation.f(root)) << std::endl;
        std::cout << "----------" << std::endl;

        std::cout << "SecantMethod: " << std::endl;
        std::cout << "Initial approximation: "
                  << abs(segment.second - segment.second - equation.f(segment.second) / equation.df(segment.first))
                  << std::endl;
        root = algorithms[3]->solve(segment, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(equation.f(root)) << std::endl;
        std::cout << "----------" << std::endl;
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

    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n" << "Initial data:" << std::endl
              << "equation: " << equation._f << std::endl
              << "Interval: [" << interval.getLeftBorder() << "; " << interval.getRightBorder() << ']' << std::endl
              << "epsilon: " << epsilon << std::endl
              << "number of segments: " << segments.size() << std::endl
              << "found segments: " << std::endl;

    for (size_t i = 0; i < segments.size(); ++i) {
        std::cout << i + 1 << "-th segment: [" << segments[i].first << "; " << segments[i].second << "]" << std::endl;
    }

    searchRoot(equation, segments);

    return 0;
}
