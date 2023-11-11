#include "LagrangeMethod.h"

double LagrangePolynom::CalculateFundamentalPoly(double argument, double point,
                                                 Table const &sorted_interpolation_table) {
    double result = 1;

    for (auto const &pair: sorted_interpolation_table) {
        if (pair.first != point) {
            result *= (argument - pair.first) / (point - pair.first);
        }
    }
    return result;
}

double LagrangePolynom::GetInterpolatedValue(double argument, double degree) const {
    Table const sorted_interpolation_table = CreateSortedInterpolationTable(argument, degree);

    double result = 0;

    for (auto const &[x, y]: sorted_interpolation_table) {
        result += CalculateFundamentalPoly(argument, x, sorted_interpolation_table) * y;
    }

    return result;
}