#include <iostream>
#include <vector>
#include "transformSystem.h"
#include "point.h"
#include "affineTransform.h"
#include "fileIO.h"

using namespace std;

int main() {
    // // TEST *start*
    // Transform t 
    // {
    //     AffineTransform(1, 2, 3, 4, 9, 9), AffineTransform(1, 2, 3, 4, 9, 9)
    // };  
    // Point2D p = t(Point2D(1, 1));
    // cout << "Resulting point: (" << p.x << ", " << p.y << ")" << endl;
    // // TEST *end*

    // return 0;


    int N;
    Point2D start;
    vector<AffineTransform> transforms;


    FileIO::read_file("F:\\C++\\Lab1\\input.txt", N, start, transforms);
    Transform system(transforms);

    vector<Point2D> points;
    points.reserve(N);
    points.push_back(system(start));

    for (int i = 1; i < N; i++) {
        points.push_back(system(points.back()));
    }

    FileIO::write_in_file("F:\\C++\\Lab1\\output.txt", points);

    // for (const auto point : points) {
    //     cout << point.x << " " << point.y << endl;
    // }

    return 0;
}
