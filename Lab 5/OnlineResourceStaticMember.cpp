// C++ Program to demonstrate
// the working of a static data member (string type)
#include <iostream>
#include <string>
using namespace std;

// creating a demo class with a static data member of type string
class A {
public:
    // static data member of type string
    static string city;
    A() { 
        cout << "A's Constructor Called " << endl; 
    }
};

// Initialize the static string member with "Vancouver"
string A::city = "Vancouver";

// Driver code
int main() {

    // Statement 1: accessing static member without creating
    // the object
    cout << "Accessing static member without creating the object: ";
    // This verifies the independence of the static data member from the instances
    cout << A::city << endl;
    cout << endl;

    // Statement 2: Creating a single object to verify if
    // the separate instance will be created for each object
    cout << "Creating object now: ";
    A obj1;
    cout << endl;

    // Statement 3: Creating multiple objects to verify that
    // each object will refer to the same static member
    cout << "Creating another object now: ";
    A obj2;
    cout << "Printing values from each object and class name:" << endl;

    cout << "obj1.city: " << obj1.city << endl;
    cout << "obj2.city: " << obj2.city << endl;
    cout << "A::city: " << A::city << endl;

    return 0;
}
