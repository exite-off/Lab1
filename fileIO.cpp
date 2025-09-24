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

    double a11, a12, a21, a22, b1, b2;
    while(file >> a11 >> a12 >> a21>> a22>> b1>> b2){
        AffineTransform t(a11, a12, a21, a22, b1, b2);
        transforms.push_back(t);
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
    output_file.close();
    cout << "successfully input " << points.size() << " points in " << filepath << endl;
}
