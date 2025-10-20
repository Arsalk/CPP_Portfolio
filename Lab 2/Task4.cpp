#include <iostream>
using namespace std;

//calculate delivery charges
double calculateDeliveryCharges(double weight, double distance, double rate = 0.50, double insurance = 5.00, bool priority = false) {
    // Calculate the base total charges
    double totalCharges = (weight * distance * rate) + insurance;

    if (priority) {
        totalCharges += totalCharges * 0.10; 
    }

    return totalCharges;
}

int main() {
    //weight and distance
    double weight1 = 10.0, distance1 = 100.0;
    cout << "Total Charges (weight, distance): " << calculateDeliveryCharges(weight1, distance1) << endl;

    //weight, distance, and a custom rate
    double weight2 = 5.0, distance2 = 50.0, customRate = 0.60;
    cout << "Total Charges (weight, distance, custom rate): " << calculateDeliveryCharges(weight2, distance2, customRate) << endl;

    //all arguments except priority
    double weight3 = 8.0, distance3 = 200.0, customRate3 = 0.55, customInsurance = 7.00;
    cout << "Total Charges (weight, distance, custom rate, custom insurance): " << calculateDeliveryCharges(weight3, distance3, customRate3, customInsurance) << endl;

    //all arguments including priority = true
    double weight4 = 12.0, distance4 = 150.0, customRate4 = 0.70, customInsurance4 = 10.00;
    bool priorityShipping = true;
    cout << "Total Charges (weight, distance, custom rate, custom insurance, priority): " 
         << calculateDeliveryCharges(weight4, distance4, customRate4, customInsurance4, priorityShipping) << endl;

    return 0;
}
