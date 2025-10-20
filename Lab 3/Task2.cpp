#include <iostream>
using namespace std;

// Defining the Point structure
struct Point {
    int x;  // X-coordinate
    int y;  // Y-coordinate
};

// Defining the Rectangle structure with two Points
struct Rectangle {
    Point topLeft;     // Top-left corner point
    Point bottomRight; // Bottom-right corner point
};

// Function to compute the area of the rectangle
int computeArea(Rectangle rect) {
    // Calculate width and height
    int width = rect.bottomRight.x - rect.topLeft.x;
    int height = rect.topLeft.y - rect.bottomRight.y;
    
    // Return the area
    return width * height;
}

int main() {
    Rectangle rect;

    // Getting input for the top-left and bottom-right points
    cout << "Enter top-left coordinates (x y): ";
    cin >> rect.topLeft.x >> rect.topLeft.y;
    
    cout << "Enter bottom-right coordinates (x y): ";
    cin >> rect.bottomRight.x >> rect.bottomRight.y;

    // Calculating and displaying the area
    int area = computeArea(rect);
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}
