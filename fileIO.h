#pragma once
#include <string>
#include <vector>
#include "point.h"
#include "affineTransform.h"

class FileIO {
public: 
    static void read_file(const std::string &filepath, int &N, Point2D &startPoint, std::vector<AffineTransform> &transforms);

    static void write_in_file(const std::string &filepath, const std::vector<Point2D> &points);
};