#include <iostream>
using namespace std;

// Declare class Point with two integer data members: x and y
class Point {
private:
    int x, y;

public:
    // Constructor to initialize the data members to 0
    Point() : x(0), y(0) {}

    // Getter methods for x and y
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    // Setter methods for x and y
    void setX(int xVal) {
        x = xVal;
    }

    void setY(int yVal) {
        y = yVal;
    }

    // Display function to print x and y in the required format
    void display() {
        cout << "Point coordinates: " << x << ", " << y << endl;
    }
};

int main() {
    // Declare two objects of Point
    Point point1, point2;

    // Display the initial coordinates for both points
    point1.display();
    point2.display();

    // Change values of x and y using set functions
    int x1, y1, x2, y2;

    // Taking inputs from the user for the first point
    cout << "Enter new x and y for the first point: ";
    cin >> x1 >> y1;
    point1.setX(x1);
    point1.setY(y1);

    // Taking inputs from the user for the second point
    cout << "Enter new x and y for the second point: ";
    cin >> x2 >> y2;
    point2.setX(x2);
    point2.setY(y2);

    // Display the updated coordinates for both points
    point1.display();
    point2.display();

    // Add x and y coordinates together and print the result
    int sumX = point1.getX() + point2.getX();
    int sumY = point1.getY() + point2.getY();
    cout << "Sum of x coordinates: " << sumX << endl;
    cout << "Sum of y coordinates: " << sumY << endl;

    return 0;
}
