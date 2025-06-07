#include <iostream>
#include "convexHull.h"
#include "Polygon.h"

int main() {
    std::vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}
    };

    std::vector<Point> hull = ConvexHull::giftWrapping(points);

    std::cout << "The points in the convex hull are:\n";
    ConvexHull::printPoints(hull);
    return 0;
}