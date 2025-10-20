#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string vehicleType;
public:
    // Constructor with a parameter to specify vehicle type
    Vehicle(string type) : vehicleType(type) {
        cout << "This is a " << vehicleType << "\n";
    }

    // Method to display vehicle type
    void displayType() const {
        cout << "Vehicle type: " << vehicleType << "\n";
    }
};

// First subclass derived from Vehicle
class FourWheeler : public Vehicle {
protected:
    int wheels;
public:
    // Constructor that passes vehicle type to base class constructor
    FourWheeler(int wheelCount) : Vehicle("4-Wheeler"), wheels(wheelCount) {
        cout << "This vehicle has " << wheels << " wheels\n";
    }

    // Method to display number of wheels
    void displayWheels() const {
        cout << "Number of wheels: " << wheels << "\n";
    }
};

// Second subclass derived from FourWheeler
class Car : public FourWheeler {
public:
    // Constructor that passes the number of wheels to the FourWheeler constructor
    Car() : FourWheeler(4) {
        cout << "This 4-wheeler vehicle is a Car\n";
    }

    // Method specific to Car class
    void drive() const {
        cout << "The car is ready to drive!\n";
    }
};

// Main function
int main() {
    // Creating an object of the Car class
    Car obj;
    obj.displayType();   // Calling method from Vehicle class
    obj.displayWheels(); // Calling method from FourWheeler class
    obj.drive();         // Calling method from Car class
    return 0;
}
