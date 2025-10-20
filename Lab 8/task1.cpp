#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string modelName;

public:
    Vehicle(string name) : modelName(name) {}

    virtual double calculatePerformance() const = 0;

    string getModelName() const {
        return modelName;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    double mileage;           // miles per gallon
    double fuelTankCapacity;  // in gallons

public:
    Car(string name, double mileage, double fuelTankCapacity)
        : Vehicle(name), mileage(mileage), fuelTankCapacity(fuelTankCapacity) {}

    double calculatePerformance() const override {
        return mileage * fuelTankCapacity;
    }
};

class Truck : public Vehicle {
private:
    double mileage;       // miles per gallon
    double cargoWeight;   // in pounds

public:
    Truck(string name, double mileage, double cargoWeight)
        : Vehicle(name), mileage(mileage), cargoWeight(cargoWeight) {}

    double calculatePerformance() const override {
        return cargoWeight / mileage;
    }
};

int main() {
    Car myCar("Toyota Camry", 30, 15);
    Truck myTruck("Ford F-150", 15, 2000);

    Vehicle* vehicles[2];
    vehicles[0] = &myCar;
    vehicles[1] = &myTruck;

    for (int i = 0; i < 2; ++i) {
        cout << "Model: " << vehicles[i]->getModelName() << endl;
        cout << "Performance Metric: " << vehicles[i]->calculatePerformance() << endl;
        cout << "---------------------------------" << endl;
    }

    return 0;
}
