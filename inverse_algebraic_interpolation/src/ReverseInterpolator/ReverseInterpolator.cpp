#include "ReverseInterpolator.h"

#include "../../../solving_nonlinear_equations/src/interval.h"
#include "../../../solving_nonlinear_equations/src/algorithm/methods/BisectionMethod.h"

std::vector<double> ReverseInterpolator::getArguments(double functionValue, int degree) const {
    auto const function = [degree, functionValue, this](double argument) { return this->GetInterpolatedValue(argument, degree) - functionValue; };

    std::vector<std::pair<double, double>> const separatedRoots = GetSeparatedRoots((*interpolation_table_.begin()).first,
                                                                                    (*interpolation_table_.rbegin()).first,
                                                                                    splitCount, function);
    std::vector<double> result;

    for (auto const& segment : separatedRoots) {
        double const currentRoot = secantMethod(segment, eps, function);
        result.push_back(currentRoot);
    }

    return result;
}