#pragma once

#include <vector>
#include "point.h"

class AffineTransform{
private:
    double a11, a12, a21, a22;
    double b1, b2;
public:
    AffineTransform(double a11, double a12, double a21, double a22, double b1, double b2);

    Point2D applyToPoint(const Point2D &p) const;
};