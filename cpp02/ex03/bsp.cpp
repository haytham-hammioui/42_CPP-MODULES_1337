#include "Point.hpp"

static Fixed triangleArea(Point const a, Point const b, Point const c) {
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                  (b.getX() * (c.getY() - a.getY())) +
                  (c.getX() * (a.getY() - b.getY()))) / Fixed(2);
    return (area < Fixed(0)) ? area * Fixed(-1) : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = triangleArea(a, b, c);
    Fixed A1 = triangleArea(point, b, c);
    Fixed A2 = triangleArea(a, point, c);
    Fixed A3 = triangleArea(a, b, point);

    if ((A == A1 + A2 + A3) && A1 != Fixed(0) && A2 != Fixed(0) && A3 != Fixed(0))
        return true;
    return false;
}