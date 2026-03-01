#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point inside(1, 1);
    Point edge(0, 0);
    Point outside(6, 6);

    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Edge: " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
}