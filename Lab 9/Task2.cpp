#include <iostream>
#include <stdexcept>

class InvalidRange : public std::exception {
private:
    std::string message;

public:
    InvalidRange(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Student {
private:
    int age;
    int marks;

public:
    Student(int a, int m) {
        setAge(a);
        setMarks(m);
    }

    void setAge(int a) {
        if (a < 15 || a > 40) {
            throw InvalidRange("Age must be between 15 and 40.");
        }
        age = a;
    }

    void setMarks(int m) {
        if (m < 0 || m > 100) {
            throw InvalidRange("Marks must be between 0 and 100.");
        }
        marks = m;
    }

    void display() const {
        std::cout << "Student Info: Age = " << age << ", Marks = " << marks << std::endl;
    }
};

int main() {
    int age, marks;

    try {
        std::cout << "Enter the student's age: ";
        std::cin >> age;

        std::cout << "Enter the student's marks: ";
        std::cin >> marks;

        Student student(age, marks);

        student.display();
    } catch (const InvalidRange& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
