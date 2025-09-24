#include <iostream>
#include <vector>
#include "transformSystem.h"
#include "point.h"
#include "affineTransform.h"
#include "fileIO.h"

using namespace std;

int main() {

    int N;
    Point2D start;
    vector<AffineTransform> transforms;

    FileIO::read_file("C:\\Users\\vfedi\\CLionProjects\\Lab1\\SampleInput.txt", N, start, transforms);
    Transform system(transforms);

    vector<Point2D> points;
    points.reserve(N);
    points.push_back(system(start));

    for (int i = 1; i < N; i++) {
        points.push_back(system(points.back()));
    }

    FileIO::write_in_file("C:\\Users\\vfedi\\CLionProjects\\Lab1\\out.txt", points);

    return 0;
}
