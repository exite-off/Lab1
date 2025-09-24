#include "transformSystem.h"

#include <iostream>

#include "point.h"
#include <random>

using namespace std;

Transform::Transform(initializer_list<AffineTransform> transforms) {
    random_device rd;
    this->gen = mt19937(rd());
    this->dist = uniform_int_distribution<int>(0, transforms.size() - 1);
    for (const auto& transform : transforms) {
        this->affineTransforms.push_back(transform);
    }
}

Point2D Transform::operator()(Point2D point) {
    // TODO: Implement the transformation logic here
    return point;
}


