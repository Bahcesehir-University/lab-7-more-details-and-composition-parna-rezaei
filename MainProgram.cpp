#include <iostream>
#include <string>
#include <cmath>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void display() const { std::cout << "(" << x << ", " << y << ")"; }

    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    Rectangle(double x1, double y1, double x2, double y2)
    : topLeft(x1, y1), bottomRight(x2, y2) {}

    double getWidth() const { return std::abs(bottomRight.x - topLeft.x); }
    double getHeight() const { return std::abs(topLeft.y - bottomRight.y); }
    double getArea() const { return getWidth() * getHeight(); }


    void display(int id) const {
    std::cout << "Rect" << id << ":" << std::endl;
    std::cout << "Top Left: "; topLeft.display(); std::cout << std::endl;
    std::cout << "BottomRight: "; bottomRight.display(); std::cout << std::endl;
    std::cout << "Width: " << getWidth() << ", Height: " << getHeight() << ", Area: " << getArea() << std::endl;
    std::cout << std::endl;
    }

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getArea() == r2.getArea());
}

class ConstDemo {
private:
    int value;
public:
    ConstDemo(int v) : value(v) {}
    int getValue() const { return value; }
    void doubleValue() { value *= 2; }
    int constGetDouble() const { return value * 2; }
};

// ============================================================
// MAIN
// ============================================================

int main() {

    Rectangle r1(0, 0, 4, 3);
    Rectangle r2(1, 1, 4, 4);

    r1.display(1);
    r2.display(2);

    std::cout << "Same Size? " << (isSameSize(r1, r2) ? "Yes" : "No") << std::endl;
    std::cout << "\n=== Code Execution Successful ===" << std::endl;

    return 0;
}
