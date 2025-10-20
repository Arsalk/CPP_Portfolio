#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string firstName;
    string lastName;

public:
    Person(string fName = "First", string lName = "Last") : firstName(fName), lastName(lName) {}

    void getFullName() const {
        cout << "Full Name: " << firstName << " " << lastName << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;
    string department;

public:
    Employee(int empID = 0, string dept = "Department", string fName = "First", string lName = "Last")
        : Person(fName, lName), employeeID(empID), department(dept) {}

    void getEmployeeDetails() const {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(int empID = 0, string dept = "Department", int tSize = 0, string fName = "First", string lName = "Last")
        : Employee(empID, dept, fName, lName), teamSize(tSize) {}

    void getManagerDetails() const {
        getFullName();
        getEmployeeDetails();
        cout << "Team Size: " << teamSize << endl;
    }
};

int main() {
    Person person("John", "Doe");
    person.getFullName();

    cout << endl;

    Employee employee(123, "HR", "Jane", "Smith");
    employee.getEmployeeDetails();

    cout << endl;

    Manager manager(456, "Sales", 10, "Alice", "Johnson");
    manager.getManagerDetails();

    return 0;
}
