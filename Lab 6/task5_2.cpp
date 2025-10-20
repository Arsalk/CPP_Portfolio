#include <iostream>
using namespace std;

// First base class
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

// Second base class
class FourWheeler {
protected:
    int wheels;
public:
    // Constructor with a parameter
    FourWheeler(int wheelCount) : wheels(wheelCount) {
        cout << "This vehicle has " << wheels << " wheels\n";
    }

    // Method to display the number of wheels
    void displayWheels() const {
        cout << "Number of wheels: " << wheels << "\n";
    }
};

// Derived class using multiple inheritance
class Car : public Vehicle, public FourWheeler {
public:
    // Constructor that passes arguments to both base class constructors
    Car() : Vehicle("Car"), FourWheeler(4) {
        cout << "This 4-wheeler vehicle is a Car\n";
    }

    // Method specific to the Car class
    void drive() const {
        cout << "The car is ready to drive!\n";
    }
};

// Main function
int main() {
    // Creating an object of the derived class
    Car obj;
    obj.displayType();   // Calling method from Vehicle class
    obj.displayWheels(); // Calling method from FourWheeler class
    obj.drive();         // Calling method from Car class
    return 0;
}
