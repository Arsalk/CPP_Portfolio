#include <iostream>
using namespace std;

class Point {
private:
    float x, y; 

public:
    Point(float x = 0.0, float y = 0.0) : x(x), y(y) {}

    float getX() const { return x; }

    float getY() const { return y; }

    void setX(float newX) { x = newX; }

    void setY(float newY) { y = newY; }

    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    friend Point operator+(const Point& p, float scalar);
};

Point operator+(const Point& p, float scalar) {
    return Point(p.x + scalar, p.y); // Add scalar only to the x-coordinate
}

int main() {
    Point p1(3.2, 4.6);
    Point p2(4.5, 7.1);

    Point p3 = p1 + p2;

    cout << "Result of p1 + p2: ";
    p3.display();

    Point p4 = p1 + 2.5;

    cout << "Result of p1 + 2.5: ";
    p4.display();

    return 0;
}