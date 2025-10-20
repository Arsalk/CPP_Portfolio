#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string vehicleType;

public:
    // Constructor with a parameter
    Vehicle(string type) : vehicleType(type) {
        cout << "This is a " << vehicleType << "\n";
    }

    // Method to display the vehicle type
    void displayType() const {
        cout << "Vehicle type: " << vehicleType << "\n";
    }
};

// Derived class (Single Inheritance)
class Car : public Vehicle {
public:
    // Constructor that passes "Car" as the type to the base class
    Car() : Vehicle("Car") {
        cout << "This vehicle is a Car\n";
    }

    // Method specific to Car class
    void drive() const {
        cout << "The car is ready to drive!\n";
    }
};

// Main function
int main() {
    // Creating an object of the derived class
    Car obj;
    obj.displayType();  // Calling a method from the base class
    obj.drive();        // Calling a method from the derived class
    return 0;
}
