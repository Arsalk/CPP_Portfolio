#include <iostream>
#include <cmath>  // for M_PI constant
using namespace std;

// Define the Circle class with a private data member radius
class Circle {
private:
    double radius;

public:
    // Constructor that sets the value of radius
    Circle(double r) : radius(r) {}

    // Method to compute the area of the circle
    double computeArea() {
        return M_PI * radius * radius;
    }

    // Method to compute the circumference of the circle
    double computeCircumference() {
        return 2 * M_PI * radius;
    }
};

int main() {
    // Prompt the user for the radius
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    // Instantiate the Circle class with the given radius
    Circle circle(r);

    // Call the methods to calculate area and circumference, and display the results
    cout << "Area of the circle: " << circle.computeArea() << endl;
    cout << "Circumference of the circle: " << circle.computeCircumference() << endl;

    return 0;
}
