#include <iostream>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    int accountPin;
    int accountBalance;

public:
    // Constructor
    BankAccount(int accNum, int accPin, int initialBalance)
        : accountNumber(accNum), accountPin(accPin), accountBalance(initialBalance) {}

    // Function to authenticate user
    bool authenticateUser() {
        int inputNumber;
        int inputPin;

        cout << setw(25) << right;
        cout << " Welcome to ABC Bank" << endl;
        cout << " ------------------------" << endl;
        cout << endl;
        cout << "Please enter your account number: ";
        cin >> inputNumber;
        cout << endl;
        cout << "Please enter your PIN: ";
        cin >> inputPin;

        if (inputNumber == accountNumber && inputPin == accountPin) {
            cout << "Authentication successful." << endl;
            cout << endl;
            return true;
        } else {
            cout << "Wrong Account Number or PIN!!" << endl;
            return false;
        }
    }

    // Function to display menu and get user choice
    int showMenu() const {
        int choice;
        cout << " Welcome to ABC Bank" << endl;
        cout << endl;
        cout << " Main menu" << endl;
        cout << " ---------------" << endl;
        cout << "1- View my balance" << endl;
        cout << "2- Withdraw cash" << endl;
        cout << "3- Deposit cash" << endl;
        cout << "4- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        return choice;
    }

    // Function to view balance
    void viewBalance() const {
        cout << "ACCOUNT BALANCE: " << accountBalance << endl;
        cout << endl;
    }

    // Function to withdraw cash
    void withdrawCash() {
        int withdrawalAmount;

        cout << "Please Enter Withdrawal Amount: ";
        cin >> withdrawalAmount;

        if (withdrawalAmount <= accountBalance) {
            accountBalance -= withdrawalAmount;
            cout << "Your new Account Balance is: " << accountBalance << endl;
            cout << endl;
        } else {
            cout << "Not enough balance!!" << endl;
            cout << endl;
        }
    }

    // Function to deposit cash
    void depositCash() {
        int depositAmount;

        cout << "Please enter Deposit Amount: ";
        cin >> depositAmount;

        accountBalance += depositAmount;
        cout << "Your new Account Balance is: " << accountBalance << endl;
        cout << endl;
    }
};

int main() {
    // Create a BankAccount object with initial values
    BankAccount account(12345, 54321, 1000);

    if (account.authenticateUser()) {
        int choice;

        do {
            choice = account.showMenu();

            switch (choice) {
                case 1:
                    account.viewBalance();
                    break;
                case 2:
                    account.withdrawCash();
                    break;
                case 3:
                    account.depositCash();
                    break;
                case 4:
                    cout << "Exiting program. Thank you!" << endl;
                    break;
                default:
                    cout << "Invalid selection, please try again..!" << endl;
                    cout << endl;
            }
        } while (choice != 4);
    }

    return 0;
}
