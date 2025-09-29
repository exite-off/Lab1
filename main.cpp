// Compiler - MSVC, Authors: Vitalii Fedin, Andrii Itsko

#include <iostream>
#include <vector>
#include "transformSystem.h"
#include "point.h"
#include "affineTransform.h"
#include "fileIO.h"

using namespace std;

int main(const int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <inputFile> <outputFile>" << std::endl;
        return 1;
    }

    string input_path = argv[1];
    string output_path = argv[2];

    int N;
    Point2D start;
    vector<AffineTransform> transforms;

    try {
        FileIO::read_file(input_path, N, start, transforms);
    } catch (const std::exception &e) {
        std::cerr << "Error reading input file: " << e.what() << std::endl;
        return 1;
    }

    Transform system(transforms);

    vector<Point2D> points;
    points.reserve(N);
    points.push_back(system(start));

    for (int i = 1; i < N; i++) {
        points.push_back(system(points.back()));
    }

    try {
        FileIO::write_in_file(output_path, points);
    } catch (const std::exception &e) {
        std::cerr << "Error writing output file: " << e.what() << std::endl;
    }

    return 0;
}
