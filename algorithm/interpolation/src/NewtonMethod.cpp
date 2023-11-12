#include <NewtonMethod.h>

std::vector<double> NewtonPolynom::CreateDividedDiffTable(Table const &sorted_interpolation_table) {
    auto difference_product = [&](std::size_t i, std::size_t n) -> double {
        double result = 1;

        for (std::size_t j = 0; j <= n; ++j) {
            if (i != j) {
                result *= (sorted_interpolation_table[i].first - sorted_interpolation_table[j].first);
            }
        }

        return result;
    };

    auto calculate_divide_difference = [&](std::size_t n) -> double {
        double result = 0;

        for (std::size_t i = 0; i <= n; ++i) {
            result += (sorted_interpolation_table[i].second / difference_product(i, n));
        }

        return result;
    };

    std::vector<double> divided_difference(sorted_interpolation_table.size());

    for (std::size_t i = 0; i < divided_difference.size(); ++i) {
        divided_difference[i] = calculate_divide_difference(i);
    }

    return divided_difference;
}


double NewtonPolynom::GetInterpolatedValue(double argument, double degree) const {
    const auto sorted_interpolation_table = CreateSortedInterpolationTable(argument, degree);
    const auto divided_difference = CreateDividedDiffTable(sorted_interpolation_table);

    double result = 0;
    double parentheses_composition = 1;

    for (auto i = 0; i < degree; ++i) {
        result += divided_difference[i] * parentheses_composition;
        parentheses_composition *= (argument - sorted_interpolation_table[i].first);
    }
    return result;
}
