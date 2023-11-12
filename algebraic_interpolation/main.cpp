#include <iostream>
#include <cmath>
#include <sstream>

#include <LagrangeMethod.h>
#include <NewtonMethod.h>

double f(double x) {
    return sqrt(1 + x * x);
}

void outputInterpolation(double argument, double degree, const LagrangePolynom &lagrange_polynom,
                         const NewtonPolynom &newton_polynom) {
    double exact_value = f(argument);
    double lagrange_polynom_value = lagrange_polynom.GetInterpolatedValue(argument, degree);
    double newton_polynom_value = newton_polynom.GetInterpolatedValue(argument, degree);

    std::cout << "\nExact function value:                   " << exact_value << '\n';
    std::cout << "--------\n";
    std::cout << "Approximate Lagrange value:             " << lagrange_polynom_value << '\n';
    std::cout << "Lagrange error:                         " << std::abs(lagrange_polynom_value - exact_value) << '\n';
    std::cout << "--------\n";
    std::cout << "Approximate Newton value:               " << newton_polynom_value << '\n';
    std::cout << "Newton error:                           " << std::abs(newton_polynom_value - exact_value) << '\n';
    std::cout << "---------------------------------------------------------------\n";
}

int main() {
    std::cout.precision(18);
    std::cout.setf(std::ios::fixed);

    double begin;
    double end;
    double argument;
    double degree;
    std::size_t points;

    std::cout << "Enter begin and end" << std::endl;
    std::cin >> begin >> end;
    std::cout << "Enter number of points -> ";
    std::cin >> points;

    auto lagrange_polynom = LagrangePolynom(begin, end, points, f);
    auto newton_polynom = NewtonPolynom(begin, end, points, f);

    std::cout << "\nInterpolation table:\n";
    lagrange_polynom.PrintTable(std::cout);
    std::cout << "\n---------------------------------------------------------------\n";

    while (true) {
        std::cout << "Enter polynom degree -> ";
        std::cin >> degree;

        if (static_cast<std::size_t>(degree) > points) {
            std::cout << "Degree must not be greater than " << points << '\n';
            std::cout << "---------------------------------------------------------------\n";
            continue;
        }

        std::cout << "Enter argument to calculate function -> ";
        std::cin >> argument;

        outputInterpolation(argument, degree, lagrange_polynom, newton_polynom);
    }

    return 0;
}
