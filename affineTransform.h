#pragma once

#include <vector>
#include "point.h"

using namespace std;

struct AffineTransform {
    vector<vector<double>> matrix;
    Point2D point;
};