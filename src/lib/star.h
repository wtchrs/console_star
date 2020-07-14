// star.h
//

#pragma once

#include <cmath>
#include <memory>
#include <vector>

using COLOR = unsigned long;

const double PI = std::acos(-1.0);

#define RAD(deg) deg *PI / 180.0
#define DEG(rad) rad * 180.0 / PI

#ifndef RGB
#define RGB(r, g, b)                                              \
    ((unsigned char)r | ((unsigned short)((unsigned char)g) << 8) \
     | ((unsigned long)((unsigned char)b) << 16))
#endif

struct Rect
{
    long left;
    long top;
    long right;
    long bottom;
};

template <typename T>
struct TPoint2D
{
    T x;
    T y;
};

class Star
{
public:
    using dPoint2D = TPoint2D<double>;
    using Point2D  = TPoint2D<long>;

private:
    COLOR    color    = RGB(0, 0, 0);
    dPoint2D center   = {};
    dPoint2D velocity = {};
    double   angle    = 0.0;
    double   rotate   = 0.0;
    double   ldist    = 0.0;
    double   ratio    = 0.0;

    std::shared_ptr<dPoint2D> polygon;

public:
    Star(double x, double y, double vX, double vY, double angle, double rotate, double ldistance,
         double ratio = 0.36);

    Star(COLOR color, double x, double y, double vX, double vY, double angle, double rotate,
         double ldistance, double ratio = 0.36);

    ~Star() {}

    void neg_velocity_x() { velocity.x = -velocity.x; }

    void neg_velocity_y() { velocity.y = -velocity.y; }

    void move_for_time(const double time) {
        center.x += velocity.x * time;
        center.y += velocity.y * time;
        angle += rotate * time;
        angle = fmod(angle, RAD(72.0));
    }

    void update_polygon();

    double get_center_x() const { return center.x; }

    double get_center_y() const { return center.y; }

    COLOR get_color() const { return color; }

    template <typename T>
    std::vector<TPoint2D<T>> get_tpoints() const;

    std::vector<Point2D> get_points() const;

    bool check_inside(dPoint2D point) const;
};
