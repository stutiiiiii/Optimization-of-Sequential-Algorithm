#include "convexHull.h"

// Helper function to find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(const Point& p, const Point& q, const Point& r) {
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;          // collinear
    return (val > 0) ? 1 : 2;        // clock or counterclock wise
}

// Gift Wrapping algorithm to find the convex hull
std::vector<Point> ConvexHull::giftWrapping(std::vector<Point>& points) {
    size_t n = points.size();
    if (n < 3) return {}; // Convex hull not possible

    std::vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }

    // Start from leftmost point, keep moving counterclockwise until reach the start point again
    int p = l, q;
    do {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, x, q) is counterclockwise
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        // Now q is the most counterclockwise with respect to p, set p as q for next iteration
        p = q;

    } while (p != l); // While we don't come to the first point

    return hull;
}

// Function to print points
void ConvexHull::printPoints(const std::vector<Point>& points) {
    for (const auto& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }
}
