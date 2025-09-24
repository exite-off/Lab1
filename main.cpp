#include <iostream>
#include <vector>
#include "transformSystem.h"
#include "point.h"
#include "affineTransform.h"

using namespace std;

int main() {
    // TEST *start*
    Transform t 
    {
        AffineTransform(1, 2, 3, 4, 9, 9), AffineTransform(1, 2, 3, 4, 9, 9)
    };  
    Point2D p = t(Point2D(1, 1));
    cout << "Resulting point: (" << p.x << ", " << p.y << ")" << endl;
    // TEST *end*

    return 0;
}
