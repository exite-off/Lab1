#pragma once

#include <random>
#include "point.h"
#include "affineTransform.h"

using namespace std;

class Transform {
public:
    Transform(vector<AffineTransform> affineTransforms);
    ~Transform()=default;
    Point2D operator()(Point2D point);
private:
    vector<AffineTransform> transforms;
    mt19937 gen;
    uniform_int_distribution<int> dist;
};
