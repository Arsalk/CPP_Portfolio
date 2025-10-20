#include <iostream>
using namespace std;

// Declaration of the Point structure
struct Point
{
    int x;  // X-coordinate
    int y;  // Y-coordinate
};

// Function to get user input for a Point, passed by reference
void getInput(Point &p)
{
    cout << "Enter x and y coordinates: ";
    cin >> p.x >> p.y;
}

// Function to add two Point structures
Point addPoints(const Point &p1, const Point &p2)
{
    Point sum;
    sum.x = p1.x + p2.x;
    sum.y = p1.y + p2.y;
    return sum;
}

int main()
{
    Point point1, point2, result;

    // Getting user input for two points
    cout << "Input for point 1:\n";
    getInput(point1);
    cout << "Input for point 2:\n";
    getInput(point2);

    // Adding two points
    result = addPoints(point1, point2);

    // Displaying the result
    cout << "Sum of points: (" << result.x << ", " << result.y << ")" << endl;

    return 0;
}
