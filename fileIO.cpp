#include "fileIO.h"
#include <iostream>
#include <fstream>

using namespace std;

void FileIO::read_file(const string &filepath, int &N, Point2D &startPoint, vector<AffineTransform> &transforms)
{
    ifstream file(filepath);
    if(!file.is_open()){
        cerr << "cant open file : " << endl;
        return;
    }
    file >> N;
    file >> startPoint.x >> startPoint.y;
    cerr << "startPoint = " << startPoint.x << ", " << startPoint.y << endl;

    double a11, a12, a21, a22, b1, b2;
    int transformIndex = 0;
    while (file >> a11 >> a12 >> a21 >> a22 >> b1 >> b2) {
        transforms.emplace_back(a11, a12, a21, a22, b1, b2);
        cout << "read #" << transformIndex + 1 << ": "
            << a11 << " " << a12 << " " << a21 << " " << a22 << " " << b1 << " " << b2 << endl;
        transformIndex++;
    }
    
    if(transforms.empty()){
        cerr << "file cannot exist affine transform" << endl;
        return;
    }
}

void FileIO::write_in_file(const string &filepath, const vector<Point2D> &points)
{
    ofstream output_file(filepath);
    if(!output_file){
        cerr << "cant open file for output" << endl;
        return;
    }

    for(const auto &p: points){
        output_file << p.x << " " << p.y << endl;
    }
}
