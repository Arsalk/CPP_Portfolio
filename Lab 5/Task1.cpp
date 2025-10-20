#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string acc, double b) : accountNumber(acc), balance(b) {}

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

// Modify account function
void modifyAccount(BankAccount& account) {
    account.deposit(200);

    cout << "Balance after deposit: " << account.getBalance() << endl;

    account.withdraw(100);

    cout << "Balance after withdrawal: " << account.getBalance() << endl;
}

int main() {
    // Create a BankAccount object
    BankAccount b1("001", 0);

    cout << "Original Balance: " << b1.getBalance() << endl;

    modifyAccount(b1);

    cout << "Final Balance: " << b1.getBalance() << endl;

    return 0;
}