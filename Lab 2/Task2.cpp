#include <iostream>
using namespace std;

// Function to calculate the product, difference, and sum of two integers
void calculate(int a, int b, int &product, int &difference, int &sum) {
    product = a * b;
    difference = a - b;
    sum = a + b;
}

int main() {
    int num1, num2;
    int product, difference, sum;
    
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    calculate(num1, num2, product, difference, sum);
    
    cout << "Product: " << product << endl;
    cout << "Difference: " << difference << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}
