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
   // TODO 1
   Point(double x, double y) : x(x), y(y) {}
   // TODO 2
   double getX() const { return x; }
   // TODO 3
   double getY() const { return y; }
   // TODO 4
   void display() const { std::cout << "(" << x << ", " << y << ")"; }
   // TODO 5
   friend class Rectangle;
};
 
class Rectangle {
private:
   Point topLeft;
   Point bottomRight;
public:
   // TODO 6
   Rectangle(double x1, double y1, double x2, double y2)
       : topLeft(x1, y1), bottomRight(x2, y2) {}
   // TODO 7
   double getWidth() const {
       return std::abs(bottomRight.x - topLeft.x);
   }
   // TODO 8
   double getHeight() const {
       return std::abs(topLeft.y - bottomRight.y);
   }
   // TODO 9
   double getArea() const {
       return getWidth() * getHeight();
   }
   // TODO 10
   void display() const {
       std::cout << "Rectangle top left : ";
       topLeft.display();
       std::cout << " bottom right ";
       bottomRight.display();
       std::cout << "\n| Width: " << getWidth() << std::endl << "| Hight: " << getHeight() << std::endl << "| Area = " << getArea() << std::endl;
   }
   // TODO 11
   friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};
 
// TODO 12
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
   return r1.getArea() == r2.getArea();
}
 
class ConstDemo {
private:
   int value;
public:
   // TODO 13
   ConstDemo(int v) : value(v) {}
   // TODO 14
   int getValue() const { return value; }
   // TODO 15
   void doubleValue() { value *= 2; }
   // TODO 16
   int constGetDouble() const { return value * 2; }
};
 
// ============================================================
// MAIN
// ============================================================
int main() {
   // TODO 17-21: demo code
  std:: cout << "Complete the TODOs above!" << std ::endl;
Rectangle rect1 (0,0,4,3);
Rectangle rect2(1,1,4,4);
std:: cout << "\nRect1: \n"; rect1. display();
std:: cout << "\nRect2: \n"; rect2.display();
std:: cout << "\nSame Size? " << (isSameSize(rect1, rect2) ? "Yes" : "No") << "\n";
const ConstDemo cd1 (7);
std:: cout << "const object value: " << cd1.getValue() <<"\n";
std:: cout << "const object doubled: " << cd1. constGetDouble() << "\n";
ConstDemo cd2(5);
cd2. doubleValue() ;
std:: cout << "non-const object after doubleValue: " << cd2. getValue() << "\n";
   return 0;
}
