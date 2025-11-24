#include <stdexcept>
#include <iostream>

class Point2D {
private: 
    double x;
    double y;
public:
    Point2D() : x(0), y(0) {}

    Point2D(double x, double y) : x(x), y(y) {}

    Point2D

    void print() const {
        std::cout << x << "," << y << std::endl;
    }

};

int main(){
    Point2D p1;
    p1.print();
}
