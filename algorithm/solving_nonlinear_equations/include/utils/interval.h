#ifndef METHODS_OF_COMPUTATION_INTERVAL_H
#define METHODS_OF_COMPUTATION_INTERVAL_H

#include <vector>
#include <functional>

class Interval {
public:
    Interval(double left_border_, double right_border_, int32_t amount_splitting_,
             const std::function<double(double)> &f)
            : left_border_(left_border_), right_border_(right_border_), amount_splitting_(amount_splitting_), f_(f) {

        if (left_border_ > right_border_) {
            throw std::logic_error("left_border_ > right_border_");
        }

        separateRoots();
    }

    std::vector<std::pair<double, double>> getSegment() {
        return segments_;
    }

    [[nodiscard]] double getLeftBorder() const {
        return left_border_;
    }

    [[nodiscard]] double getRightBorder() const {
        return right_border_;
    }

private:
    void separateRoots() {
        double offset = (right_border_ - left_border_) / static_cast<double>(amount_splitting_), point = left_border_;
        double multiplication_border;

        while (point + offset <= right_border_) {
            multiplication_border = f_(point) * f_(point + offset);

            if (multiplication_border <= 0) {
                segments_.emplace_back(point, point + offset);
            }

            point += offset;
        }
    }

    double left_border_, right_border_;
    int32_t amount_splitting_;
    std::vector<std::pair<double, double>> segments_;
    std::function<double(double)> f_;
};


#endif //METHODS_OF_COMPUTATION_INTERVAL_H
