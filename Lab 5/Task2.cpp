#include <iostream>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
    static int count; 

public:
    // Constructor
    Car(string mk, string ml, int yr) : make(mk), model(ml), year(yr) {
        count++; 
    }

    // Function to display car info
    void displayInfo() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }

    // Static function to get the count of Car objects
    static int getCount() {
        return count;
    }
};

// Initialize the static count variable
int Car::count = 0;

int main() {
    // Create car1 and car2 objects
    Car car1("Toyota", "Camry", 2020);
    Car car2("Honda", "Civic", 2019);

    // Display car1 information and total count
    car1.displayInfo();
    cout << "Total Cars Created: " << Car::getCount() << endl;

    // Display car2 information and total count
    car2.displayInfo();
    cout << "Total Cars Created: " << Car::getCount() << endl;

    return 0;
}