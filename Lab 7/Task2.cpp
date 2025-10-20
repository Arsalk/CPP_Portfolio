#include <iostream>
#include <cmath> 
using namespace std;

class Shape {
public:
    virtual double area() const {
        return 0.0; 
    }
    virtual ~Shape() {} 
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius; // Area = πr²
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height; 
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height; 
    }
};

int main() {
    Shape* shape = nullptr; 
    int choice;
    cout << "Select a shape to calculate its area:\n";
    cout << "1. Circle\n2. Rectangle\n3. Triangle\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            shape = new Circle(radius); // Dynamically allocate Circle
            break;
        }
        case 2: {
            double width, height;
            cout << "Enter the width of the rectangle: ";
            cin >> width;
            cout << "Enter the height of the rectangle: ";
            cin >> height;
            shape = new Rectangle(width, height); 
            break;
        }
        case 3: {
            double base, height;
            cout << "Enter the base of the triangle: ";
            cin >> base;
            cout << "Enter the height of the triangle: ";
            cin >> height;
            shape = new Triangle(base, height); 
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    if (shape) {
        cout << "The area of the selected shape is: " << shape->area() << endl;
        delete shape; // Clean up
    }

    return 0;
}