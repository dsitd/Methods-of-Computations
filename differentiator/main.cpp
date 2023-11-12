#include <iostream>
#include <cmath>
#include <NumericalDifferentiator.h>

double f(double x) {
    return exp(1.5 * 4 * x);
}

double df(double x) {
    return 1.5 * f(x);
}

double ddf(double x) {
    return 2.25 * f(x);
}

void printTable(std::ostream &out, const std::vector<std::array<double, 6>> &values) {
    std::ios::fmtflags format(out.flags());
    out.setf(std::ios::fixed);
    out.precision(10);

    std::size_t ind_arr = 0;

    out << "\nArgument\t\t\tValue\t\t\t\tFirst derivative\tFirst der error\t\tSecond derivative\tSecond der error\n";

    for (const auto &arr: values) {

        out << arr[0] << "\t\t" << arr[1] << "\t\t" << arr[2] << "\t\t" << arr[3] << "\t\t";


        if (ind_arr == 0 || ind_arr + 1 == values.size()) {
            out << "-----------\t\t\t" << "-----------\n";
        } else {
            out << arr[4] << "\t\t" << arr[5] << '\n';
        }
        ++ind_arr;
    }

    out.flags(format);
}


int main() {
    double begin;
    double step;
    std::size_t step_count;

    while (true) {
        std::cout << "Enter begin point -> ";
        std::cin >> begin;
        std::cout << "Enter length of a step -> ";
        std::cin >> step;
        std::cout << "Enter count of steps -> ";
        std::cin >> step_count;

        auto differentiator = NumericalDifferentiator(begin, step, step_count, {f, df, ddf});

        std::cout << "\nArgument-value table:\n";
        auto values = differentiator.SearchDerivative();
        printTable(std::cout, values);
        std::cout
                << "-------------------------------------------------------------------------------------------------------------------------------------\n";
    }
}