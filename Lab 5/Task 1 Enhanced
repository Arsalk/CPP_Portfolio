#include <iostream>
#include <iomanip>  // For setting precision
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    int depositCount;
    int withdrawCount;

public:
    // Constructor
    BankAccount(string acc, double b) : accountNumber(acc), balance(b), depositCount(0), withdrawCount(0) {}

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Deposit function
    void deposit(double amount) {
        if (depositCount < 2 && amount <= 9999.99) {
            balance += amount;
            depositCount++;
            cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else if (depositCount >= 2) {
            cout << "Deposit limit reached. Max 2 deposits allowed." << endl;
        } else {
            cout << "Deposit failed! Max deposit value is $9999.99." << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (withdrawCount < 2 && amount <= 3000) {
            if (balance - amount >= 0) {
                balance -= amount;
                withdrawCount++;
                cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
            } else {
                cout << "Insufficient funds!" << endl;
            }
        } else if (withdrawCount >= 2) {
            cout << "Withdrawal limit reached. Max 2 withdrawals allowed." << endl;
        } else {
            cout << "Withdrawal failed! Max withdrawal value is $3000." << endl;
        }
    }

    // Check if user can still deposit
    bool canDeposit() {
        return depositCount < 2;
    }

    // Check if user can still withdraw
    bool canWithdraw() {
        return withdrawCount < 2;
    }

    // Check if user can perform any transaction
    bool canTransact() {
        return canDeposit() || canWithdraw();
    }
};

// Function to handle user transactions
void handleTransaction(BankAccount& account) {
    int choice;
    double amount;

    while (account.canTransact()) {
        cout << "\nWhat would you like to do?\n";
        if (account.canDeposit()) {
            cout << "1. Deposit\n";
        }
        if (account.canWithdraw()) {
            cout << "2. Withdraw\n";
        }
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 && account.canDeposit()) {
            cout << "Enter amount to deposit (up to $9999.99): ";
            cin >> amount;
            account.deposit(amount);
        } else if (choice == 2 && account.canWithdraw()) {
            cout << "Enter amount to withdraw (up to $3000): ";
            cin >> amount;
            account.withdraw(amount);
        } else if (choice == 3) {
            cout << "Exiting transaction session." << endl;
            break;
        } else {
            cout << "Invalid choice or transaction limit reached." << endl;
        }
    }

    if (!account.canTransact()) {
        cout << "Transaction limits reached. No more deposits or withdrawals allowed.\nOnly exit is available now." << endl;
    }
}

int main() {
    // Create a BankAccount object with an initial balance of 0
    BankAccount b1("001", 0);

    cout << "Welcome to the Bank Account system!" << endl;
    cout << "Your current balance is: $" << fixed << setprecision(2) << b1.getBalance() << endl;

    // Start handling user transactions
    handleTransaction(b1);

    // Display final balance
    cout << "\nFinal balance: $" << fixed << setprecision(2) << b1.getBalance() << endl;

    return 0;
}
