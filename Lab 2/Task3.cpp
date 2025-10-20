#include <iostream>
#include <cmath>  
using namespace std;

// volume of a sphere
double calculateVolume(double radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

// volume of a cone
double calculateVolume(double radius, double height) {
    return (1.0 / 3.0) * M_PI * pow(radius, 2) * height;
}

// volume of a cuboid
double calculateVolume(double length, double width, double height) {
    return length * width * height;
}

int main() {
    double radius, height, length, width;

    cout << "Enter the radius of the sphere: ";
    cin >> radius;
    cout << "Volume of the sphere: " << calculateVolume(radius) << endl;

    cout << "Enter the radius and height of the cone: ";
    cin >> radius >> height;
    cout << "Volume of the cone: " << calculateVolume(radius, height) << endl;

    cout << "Enter the length, width, and height of the cuboid: ";
    cin >> length >> width >> height;
    cout << "Volume of the cuboid: " << calculateVolume(length, width, height) << endl;

    return 0;
}
