#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize an account
    Account(string name, int number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    // Function to display account details
    void showAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    // Function to check balance
    double checkBalance() const {
        return balance;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    // Function to add a new account to the bank
    void createAccount(const string &name, int accountNumber, double initialBalance) {
        accounts.push_back(Account(name, accountNumber, initialBalance));
        cout << "Account created successfully!" << endl;
    }

    // Function to find an account by account number
    Account* findAccount(int accountNumber) {
        for (auto &account : accounts) {
            if (accountNumber == account.accountNumber) {
                return &account;
            }
        }
        return nullptr; // Account not found
    }

    // Function to display details of all accounts
    void showAllAccounts() const {
        for (const auto &account : accounts) {
            account.showAccountDetails();
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice, accountNumber;
    string name;
    double amount;

    while (true) {
        cout << "\nBank System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Show All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder name: ";
                cin.ignore(); // To clear the input buffer
                getline(cin, name);
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial deposit: ";
                cin >> amount;
                bank.createAccount(name, accountNumber, amount);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                if (Account* account = bank.findAccount(accountNumber)) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                if (Account* account = bank.findAccount(accountNumber)) {
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                if (Account* account = bank.findAccount(accountNumber)) {
                    cout << "Balance: $" << account->checkBalance() << endl;
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 5:
                bank.showAllAccounts();
                break;

            case 6:
                cout << "Exiting the system..." << endl;
                return 0;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}
