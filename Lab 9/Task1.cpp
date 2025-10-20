#include <iostream>
#include <cmath> // For M_PI

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const {
        return M_PI * radius * radius;
    }

    double getRadius() const {
        return radius;
    }
};

class Cone {
private:
    Circle base; 
    double height;

public:
    Cone(double r, double h) : base(r), height(h) {}

    double volume() const {
        return (1.0 / 3.0) * base.area() * height;
    }
};

int main() {
    double radius, height;

    std::cout << "Enter the radius of the cone's base: ";
    std::cin >> radius;

    std::cout << "Enter the height of the cone: ";
    std::cin >> height;

    Cone cone(radius, height);

    std::cout << "The volume of the cone is: " << cone.volume() << std::endl;

    return 0;
}
