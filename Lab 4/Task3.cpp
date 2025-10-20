#include <iostream>
using namespace std;

// Define the Box class
class Box {
private:
    double length;
    double breadth;
    double height;

public:
    // Parameterized constructor with default arguments of 1 for each data member
    Box(double l = 1, double b = 1, double h = 1) : length(l), breadth(b), height(h) {}

    // Member function to compute and display the volume of the box
    void displayVolume() {
        double volume = length * breadth * height;
        cout << "Volume of the box: " << volume << endl;
    }
};

int main() {
    // Creating four objects of Box class
    Box b1;          // Box with default dimensions
    Box b2(2);       // Box with length 2, default breadth and height
    Box b3(2, 3);    // Box with length 2, breadth 3, default height
    Box b4(2, 3, 4); // Box with length 2, breadth 3, height 4

    // For each Box object, call the volume function
    b1.displayVolume();
    b2.displayVolume();
    b3.displayVolume();
    b4.displayVolume();

    return 0;
}
