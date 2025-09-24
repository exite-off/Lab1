#include "transformSystem.h"

#include <iostream>

#include "point.h"
#include <random>
#include <utility>

using namespace std;

Transform::Transform(vector<AffineTransform> affineTransforms) {
    random_device rd;
    this->gen = mt19937(rd());
    this->dist = uniform_int_distribution<int>(0, affineTransforms.size() - 1);
    this->transforms = std::move(affineTransforms);
}

Point2D Transform::operator()(Point2D point) {
    // TODO: Implement the transformation logic here
    return point;
}


