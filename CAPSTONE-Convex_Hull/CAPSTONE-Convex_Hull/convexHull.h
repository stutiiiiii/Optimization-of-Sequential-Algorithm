#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <vector>
#include <iostream>

struct Point {
    float x, y;
    Point(float x = 0, float y = 0) : x(x), y(y) {}
};

class ConvexHull {
public:
    static std::vector<Point> giftWrapping(std::vector<Point>& points);
    static void printPoints(const std::vector<Point>& points);
};

#endif // CONVEXHULL_H