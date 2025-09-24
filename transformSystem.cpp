#include "transformSystem.h"

#include <iostream>

#include "point.h"
#include <random>

using namespace std;

Transform::Transform(vector<AffineTransform> affineTransforms) {
    random_device rd;
    this->gen = mt19937(rd());
    this->dist = uniform_int_distribution<int>(0, affineTransforms.size() - 1);
    this->transforms = affineTransforms;
}

Point2D Transform::operator()(Point2D point) {
    const AffineTransform transform = transforms[dist(gen)];
    const Point2D res = transform.applyToPoint(point);

    return res;
}


