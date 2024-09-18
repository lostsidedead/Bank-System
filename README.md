# Bank System - C++ Project

This is a simple Bank System implemented in C++ that simulates basic banking operations like account creation, deposit, withdrawal, balance checking, and account management. The program is written in an object-oriented manner, utilizing classes and member functions.

## Features

1. **Account Creation**: Users can create a new account by providing a name, account number, and initial balance.
2. **Deposit**: Users can deposit a specific amount into their account.
3. **Withdraw**: Users can withdraw a specific amount from their account, provided they have sufficient funds.
4. **Check Balance**: Users can check their current balance.
5. **Show All Accounts**: The bank system allows displaying details for all the accounts in the bank.
6. **Exit**: Users can exit the system.

## Files

- `main.cpp`: Contains the main C++ code for the Bank System.

## Classes

1. **Account**:
    - This class stores details about an individual account, such as the account holder's name, account number, and balance.
    - Member functions include deposit, withdraw, check balance, and show account details.

2. **Bank**:
    - The Bank class maintains a list of all accounts in the bank.
    - It contains methods to create an account, find an account by its number, and display details for all accounts.

## How to Run the Program

1. Clone or download the project files.
2. Open the terminal and navigate to the project folder.
3. Compile the C++ code using the following command:

    ```
    g++ main.cpp -o bankSystem
    ```

4. Run the executable:

    ```
    ./bankSystem
    ```

5. Follow the on-screen menu to use the banking system.

## Menu Options

- **1. Create Account**: Enter the account holder's name, account number, and initial balance to create a new account.
- **2. Deposit Money**: Enter the account number and deposit amount to increase the balance.
- **3. Withdraw Money**: Enter the account number and withdrawal amount. You can only withdraw if the balance is sufficient.
- **4. Check Balance**: Enter the account number to view the current balance.
- **5. Show All Accounts**: Displays all accounts in the bank with details.
- **6. Exit**: Exit the system.

## Future Enhancements

- Add features like transferring money between accounts.
- Implement authentication for account holders.
- Add a file system for saving account data between sessions.
