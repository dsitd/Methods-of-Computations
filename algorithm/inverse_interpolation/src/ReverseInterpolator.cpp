#include "ReverseInterpolator.h"

#include <SecantMethod.h>

std::vector<double> ReverseInterpolator::GetArguments(double value, double degree) const {
    auto const function = [degree, value, this](double argument) {
        return this->GetInterpolatedValue(argument, degree) - value;
    };

    Interval interval((*interpolation_table_.begin()).first,
                      (*interpolation_table_.rbegin()).first,
                      split_count_, function);

    std::unique_ptr<algorithm> equation = std::make_unique<SecantMethod>();

    std::vector<std::pair<double, double>> const separatedRoots = interval.getSegment();

    std::vector<double> result;

    for (auto const &segment: separatedRoots) {
        const double root = equation->solve(segment, {function}, eps_);
        result.push_back(root);
    }

    return result;
}