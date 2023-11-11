#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

#include "src/interval.h"
#include "src/algorithm/methods/BisectionMethod.h"
#include "src/algorithm/methods/NewtonMethod.h"
#include "src/algorithm/methods/ModifiedNewtonMethod.h"
#include "src/algorithm/methods/SecantMethod.h"

double f(double x) {
    return sqrt(4 * x + 7) - 3 * cos(x);
}

double df(double x) {
    return 3 * sin(x) + 2 / (sqrt(4 * x + 7));
}

double epsilon = pow(10, -8);
double left_border, right_border;
int32_t amount_splitting;

void searchRoot(const std::vector<std::function<double(double)>> &functions,
                const std::vector<std::pair<double, double>> &segments) {
    std::vector<std::unique_ptr<algorithm>> algorithms(4);
    double root;

    algorithms[0] = std::make_unique<BisectionMethod>();
    algorithms[1] = std::make_unique<NewtonMethod>();
    algorithms[2] = std::make_unique<ModifiedNewtonMethod>();
    algorithms[3] = std::make_unique<SecantMethod>();

    std::cout << std::fixed << std::setprecision(15);

    for (auto &segment: segments) {
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
        std::cout << "Segment: [" << segment.first << "; " << segment.second << "]" << std::endl;
        std::cout << "BisectionMethod: " << std::endl;
        std::cout << "Initial approximation: " << segment.second - segment.first << std::endl;

        root = algorithms[0]->solve(segment, functions, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(f(root)) << std::endl;
        std::cout << "----------" << std::endl;

        std::cout << "NewtonMethod: " << std::endl;
        std::cout << "Initial approximation: "
                  << abs(segment.first - segment.first - f(segment.first) / df(segment.first))
                  << std::endl;
        root = algorithms[1]->solve(segment, functions, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(f(root)) << std::endl;
        std::cout << "----------" << std::endl;

        std::cout << "ModifiedNewtonMethod: " << std::endl;
        std::cout << "Initial approximation: "
                  << abs(segment.first - segment.first - f(segment.first) / df(segment.first))
                  << std::endl;
        root = algorithms[2]->solve(segment, functions, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(f(root)) << std::endl;
        std::cout << "----------" << std::endl;

        std::cout << "SecantMethod: " << std::endl;
        std::cout << "Initial approximation: "
                  << abs(segment.second - segment.second - f(segment.second) / df(segment.first))
                  << std::endl;
        root = algorithms[3]->solve(segment, functions, epsilon);
        std::cout << "The found root: " << root << std::endl;
        std::cout << "Absolute value of the discrepancy: " << abs(f(root)) << std::endl;
        std::cout << "----------" << std::endl;
    }
}


int main() {
    std::cout << "Enter the interval: ";
    std::cin >> left_border >> right_border;

    std::cout << "Enter the split: ";
    std::cin >> amount_splitting;

    Interval interval(left_border, right_border, amount_splitting, f);
    std::vector<std::pair<double, double>> segments = interval.getSegment();

    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n" << "Initial data:" << std::endl
              << "equation: sqrt(4 * x + 7) - 3 * cos(x)" << std::endl
              << "Interval: [" << interval.getLeftBorder() << "; " << interval.getRightBorder() << ']' << std::endl
              << "epsilon: " << epsilon << std::endl
              << "number of segments: " << segments.size() << std::endl
              << "found segments: " << std::endl;

    for (size_t i = 0; i < segments.size(); ++i) {
        std::cout << i + 1 << "-th segment: [" << segments[i].first << "; " << segments[i].second << "]" << std::endl;
    }

    searchRoot({f, df}, segments);

    return 0;
}
