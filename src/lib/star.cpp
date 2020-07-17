// star.cpp
//

#include "star.h"

Star::Star(double x, double y, double vx, double vy, double angle, double rotate, double ldistance,
           double ratio) {
    this->center   = {x, y};
    this->velocity = {vx, vy};
    this->angle    = RAD(fmod(angle, 72.0));
    this->rotate   = RAD(rotate);
    this->ldist    = ldistance;
    this->ratio    = ratio;

    update_polygon();
}

Star::Star(COLOR color, double x, double y, double vx, double vy, double angle, double rotate,
           double ldistance, double ratio) {
    this->color    = color;
    this->center   = {x, y};
    this->velocity = {vx, vy};
    this->angle    = RAD(fmod(angle, 72.0));
    this->rotate   = RAD(rotate);
    this->ldist    = ldistance;
    this->ratio    = ratio;

    update_polygon();
}

void Star::update_polygon() {
    for (int i = 0; i < 10; i += 2) {
        polygon[i] = dPoint2D{ldist * std::cos(angle + RAD(72.0) * i) + center.x,
                              ldist * std::sin(angle + RAD(72.0) * i) + center.y};
        polygon[i + 1]
            = dPoint2D{ldist * ratio * std::cos(angle + RAD(72.0) * i + RAD(36.0)) + center.x,
                       ldist * ratio * std::sin(angle + RAD(72.0) * i + RAD(36.0)) + center.y};
    }
}

template <typename T>
std::array<TPoint2D<T>, 10> Star::get_tpoints() const {
    std::array<TPoint2D<T>, 10> result;

    for (auto elem = result.begin(), first = polygon.cbegin(), last = polygon.cend(); first != last;
         ++elem, ++first) {
        *elem = TPoint2D<T>{static_cast<T>(first->x), static_cast<T>(first->y)};
    }

    return std::move(result);
}

template <>
std::array<Star::dPoint2D, 10> Star::get_tpoints() const {
    return polygon;
}

bool Star::check_inside(dPoint2D point) const {
    int count = 0;

    for (int i = 0; i < 10; ++i) {
        int i_next = (i + 1) % 10;
        if ((polygon[i].y < point.y) != (polygon[i_next].y < point.y)) {
            double x = (polygon[i_next].x - polygon[i].x) * (point.y - polygon[i].y)
                           / (polygon[i_next].y - polygon[i].y)
                       + polygon[i].x;

            if (point.x < x) {
                ++count;
            }
        }
    }

    return (count % 2) > 0;
}