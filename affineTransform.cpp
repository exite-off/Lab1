#include <iostream>
#include "affineTransform.h"

using namespace std;

AffineTransform::AffineTransform(double a11, double a12, double a21, double a22, double b1, double b2) : a11(a11), a12(a12), a21(a21), a22(a22), b1(b1), b2(b2)
{
}

Point2D AffineTransform::operator()(const Point2D & p) const
{
    double new_x = a11 *p.x + a12 * p.y + b1;
    double new_y = a21 *p.x + a22 * p.y + b2;
    
    return Point2D(new_x, new_y);
}
