#include <iostream>

int main() {
    int num1, num2, choice;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "\nChoose an operation:\n";
    std::cout << "Press 1 for addition\n";
    std::cout << "Press 2 for subtraction\n";
    std::cout << "Press 3 for multiplication\n";
    std::cout << "Press 4 for division\n";
    std::cout << "Press 5 for finding the remainder\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case 2:
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case 3:
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case 4:
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        case 5:
            if (num2 != 0) {
                std::cout << "Result: " << num1 % num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid choice. Please select a valid operation.\n";
            break;
    }

    return 0;
}
