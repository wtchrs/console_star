// star.cpp
//

#include "star.h"

Star::Star(double x, double y, double vx, double vy, double angle, double rotate, double ldistance,
           double ratio)
    : polygon(new dPoint2D[10], std::default_delete<dPoint2D[]>()) {
    this->center   = {x, y};
    this->velocity = {vx, vy};
    this->angle    = RAD(fmod(angle, 72.0));
    this->rotate   = RAD(rotate);
    this->ldist    = ldistance;
    this->ratio    = ratio;
}

Star::Star(COLOR color, double x, double y, double vx, double vy, double angle, double rotate,
           double ldistance, double ratio)
    : polygon(new dPoint2D[10], std::default_delete<dPoint2D[]>()) {
    this->color    = color;
    this->center   = {x, y};
    this->velocity = {vx, vy};
    this->angle    = RAD(fmod(angle, 72.0));
    this->rotate   = RAD(rotate);
    this->ldist    = ldistance;
    this->ratio    = ratio;
}

void Star::update_polygon() {
    for (int i = 0; i < 10; i += 2) {
        polygon.get()[i] = dPoint2D{ldist * std::cos(angle + RAD(72.0) * i) + center.x,
                                    ldist * std::sin(angle + RAD(72.0) * i) + center.y};
        polygon.get()[i + 1]
            = dPoint2D{ldist * ratio * std::cos(angle + RAD(72.0) * i + RAD(36.0)) + center.x,
                       ldist * ratio * std::sin(angle + RAD(72.0) * i + RAD(36.0)) + center.y};
    }
}

template <typename T>
std::vector<TPoint2D<T>> Star::get_tpoints() const {
    std::vector<TPoint2D<T>> points;
    points.reserve(10);

    for (int i = 0; i < 10; i += 2) {
        points.push_back(
            TPoint2D<T>{static_cast<T>(ldist * std::cos(angle + RAD(72.0) * i) + center.x),
                        static_cast<T>(ldist * std::sin(angle + RAD(72.0) * i) + center.y)});

        points.push_back(TPoint2D<T>{
            static_cast<T>(ldist * ratio * std::cos(angle + RAD(72.0) * i + RAD(36.0)) + center.x),
            static_cast<T>(ldist * ratio * std::sin(angle + RAD(72.0) * i + RAD(36.0))
                           + center.y)});
    }

    return points;
}

template <>
std::vector<Star::dPoint2D> Star::get_tpoints() const {
    std::vector<Star::dPoint2D> points;
    points.reserve(10);

    for (int i = 0; i < 10; i += 2) {
        points.push_back(dPoint2D{ldist * std::cos(angle + RAD(72.0) * i) + center.x,
                                  ldist * std::sin(angle + RAD(72.0) * i) + center.y});

        points.push_back(
            dPoint2D{ldist * ratio * std::cos(angle + RAD(72.0) * i + RAD(36.0)) + center.x,
                     ldist * ratio * std::sin(angle + RAD(72.0) * i + RAD(36.0)) + center.y});
    }

    return points;
}

std::vector<Star::Point2D> Star::get_points() const { return this->get_tpoints<long>(); }

// bool Star::check_inside(dPoint2D point) const {
//     auto polygon = this->get_tpoints<double>();
//     int  count   = 0;

//     for (int i = 0; i < 10; i++) {
//         int i_next = (i + 1) % 10;

//         if ((polygon[i].y < point.y) != (polygon[i_next].y < point.y)) {
//             double x = (polygon[i_next].x - polygon[i].x) * (point.y - polygon[i].y)
//                            / (polygon[i_next].y - polygon[i].y)
//                        + polygon[i].x;

//             if (point.x < x) {
//                 ++count;
//             }
//         }
//     }

//     return (count % 2) > 0;
// }

bool Star::check_inside(dPoint2D point) const {
    int count = 0;

    for (int i = 0; i < 10; ++i) {
        int i_next = (i + 1) % 10;
        if ((polygon.get()[i].y < point.y) != (polygon.get()[i_next].y < point.y)) {
            double x = (polygon.get()[i_next].x - polygon.get()[i].x)
                           * (point.y - polygon.get()[i].y)
                           / (polygon.get()[i_next].y - polygon.get()[i].y)
                       + polygon.get()[i].x;
            if (point.x < x) ++count;
        }
    }

    return (count % 2) > 0;
}