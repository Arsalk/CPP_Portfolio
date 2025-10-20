#include <iostream>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
    string colour; // New property for car colour
    static int count; 

public:
    // Constructor with colour added
    Car(string mk, string ml, int yr, string clr) : make(mk), model(ml), year(yr), colour(clr) {
        count++; 
    }

    // Function to display car info
    void displayInfo() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Colour: " << colour << endl;
    }

    // Static function to get the count of Car objects
    static int getCount() {
        return count;
    }
};

// Initialize the static count variable
int Car::count = 0;

int main() {
    // Create car1, car2, and car3 objects
    Car car1("Toyota", "Camry", 2020, "White");
    Car car2("Honda", "Civic", 2019, "Red");
    Car car3("BMW", "X5", 2022, "Black"); // Third car (BMW X5 2022 Black)

    // Display car1 information and total count
    car1.displayInfo();
    cout << "Total Cars Created: " << Car::getCount() << endl;

    // Display car2 information and total count
    car2.displayInfo();
    cout << "Total Cars Created: " << Car::getCount() << endl;

    // Display car3 information and total count
    car3.displayInfo();
    cout << "Total Cars Created: " << Car::getCount() << endl;

    return 0;
}
