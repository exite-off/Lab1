#include "fileIO.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void FileIO::read_file(const string &filepath, int &N, Point2D &startPoint, vector<AffineTransform> &transforms) {
    ifstream file(filepath);
    if(!file.is_open()) {
        throw std::runtime_error("Input file can not be opened!");
    }
    file >> N;
    file >> startPoint.x >> startPoint.y;

    if (N <= 0) {
        throw logic_error("N must be greater than 0");
    }

    double a11, a12, a21, a22, b1, b2;
    while(file >> a11 >> a12 >> a21>> a22>> b1>> b2){
        transforms.emplace_back(a11, a12, a21, a22, b1, b2);
    }
    
    if(transforms.empty()) {
        throw logic_error("No transforms were read from the file");
    }
}

void FileIO::write_in_file(const string &filepath, const vector<Point2D> &points) {
    ofstream output_file(filepath);
    if(!output_file) {
        throw runtime_error("Output file can not be opened!");
    }

    for(const auto &p: points) {
        output_file << p.x << " " << p.y << endl;
    }
    output_file.close();
    cout << "successfully wrote " << points.size() << " points in " << filepath << endl;
}
