#include <ReverseInterpolator.h>
#include <MonotoneReverseInterpolator.h>
#include <cmath>
#include <iostream>

double f(double x) {
    return sqrt(1 + x * x);
}

void outputInterpolation(const ReverseInterpolator &reverse_interpolator,
                         const MonotoneReverseInterpolator &monotone_reverse_interpolator,
                         double value, double degree) {

    std::vector<double> revInterpResult = reverse_interpolator.GetArguments(value, degree);
    std::vector<double> monRevInterpResult = monotone_reverse_interpolator.GetArguments(value, degree);

    std::cout << "\nMonotone reverse interpolation result:\n";
    std::cout << "Value\t\t\t\t\t| Error\n";
    for (auto const &argument: monRevInterpResult) {
        std::cout << argument << "\t| " << abs(f(argument) - value) << '\n';
    }
    std::cout << "--------\n";
    std::cout << "Reverse interpolation results:\n";
    std::cout << "Value\t\t\t\t\t| Error\n";
    for (auto const &argument: revInterpResult) {
        std::cout << argument << "\t| " << abs(f(argument) - value) << '\n';
    }
    std::cout << "---------------------------------------------------------------\n";
}

int main() {
    std::cout.precision(18);
    std::cout.setf(std::ios::fixed);

    double begin;
    double end;
    double value;
    double degree;
    double eps;
    unsigned split_count;
    std::size_t points;

    std::cout << "Enter [begin; end] -> ";
    std::cin >> begin >> end;
    std::cout << "Enter number of points -> ";
    std::cin >> points;
    std::cout << "Enter split count -> ";
    std::cin >> split_count;
    std::cout << "Enter epsilon -> ";
    std::cin >> eps;

    auto reverse_interpolator = ReverseInterpolator(begin, end, points, eps, split_count, f);
    auto monotone_reverse_interpolator = MonotoneReverseInterpolator(begin, end, points, f);

    std::cout << "\nInterpolation table:\n";
    reverse_interpolator.PrintTable(std::cout);
    std::cout << "\n---------------------------------------------------------------\n";

    while (true) {
        std::cout << "Enter polynom degree -> ";
        std::cin >> degree;

        if (static_cast<unsigned>(degree) > points) {
            std::cout << "Degree must not be greater than " << points << '\n';
            std::cout << "---------------------------------------------------------------\n";
            continue;
        }

        std::cout << "Enter function value to calculate arguments -> ";
        std::cin >> value;

        outputInterpolation(reverse_interpolator, monotone_reverse_interpolator, value, degree);
    }
}