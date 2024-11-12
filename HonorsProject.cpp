#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

static const int MAX_CUSTOMERS = 10;
static const int MAX_FAMILY_MEMBERS = 5;

class Bank 
{
private:
  string BankName;
  int numCustomers;

public:
  class Customer 
  {
  private:
    string customerName;
    bool isFamily;
    int numFamilyMembers;
    string familyMembers[MAX_FAMILY_MEMBERS];
    long long int AcctNumber;
    double checkingBalance;
    double savingsBalance;
    double familyBalance;
    string depositType;
    string withdrawalType;
    int checkingDepositCount;
    int savingsDepositCount;
    int familyDepositCount;
    int checkingWithdrawalCount;
    int savingsWithdrawalCount;
    int familyWithdrawalCount;
    double totalCheckingDepositAmount;
    double totalSavingsDepositAmount;
    double totalFamilyDepositAmount;
    double totalCheckingWithdrawalAmount;
    double totalSavingsWithdrawalAmount;
    double totalFamilyWithdrawalAmount;
    double checkingOverdraftCharges;
    double savingsOverdraftCharges;
    double familyOverdraftCharges;

  public:
    Customer() 
    {
      customerName = "";
      isFamily = false;
      numFamilyMembers = 0;
      AcctNumber = 0;
      checkingBalance = 0;
      savingsBalance = 0;
      familyBalance = 0;
      checkingDepositCount = 0;
      savingsDepositCount = 0;
      familyDepositCount = 0;
      checkingWithdrawalCount = 0;
      savingsWithdrawalCount = 0;
      familyWithdrawalCount = 0;
      totalCheckingDepositAmount = 0;
      totalSavingsDepositAmount = 0;
      totalFamilyDepositAmount = 0;
      totalCheckingWithdrawalAmount = 0;
      totalSavingsWithdrawalAmount = 0;
      totalFamilyWithdrawalAmount = 0;
      checkingOverdraftCharges = 0;
      savingsOverdraftCharges = 0;
      familyOverdraftCharges = 0;
    }

    void deposit(string accountType, double amount) 
    {
      if (amount <= 0) 
      {
        cout << "Invalid amount. Please enter a positive number." << endl;
        return;
      }

      cout << fixed << setprecision(2);
      if (accountType == "checking") 
      {
        checkingBalance += amount;
        checkingDepositCount++;
        totalCheckingDepositAmount += amount;
        cout << "Deposit of $" << amount << " to checking account successful."
             << endl;
        cout << "New checking balance: $" << checkingBalance << endl;
      } 
      else if (accountType == "savings") 
      {
        savingsBalance += amount;
        savingsDepositCount++;
        totalSavingsDepositAmount += amount;
        cout << "Deposit of $" << amount << " to savings account successful."
             << endl;
        cout << "New savings balance: $" << savingsBalance << endl;
      } 
      else if (accountType == "family" && isFamily) 
      {
        familyBalance += amount;
        familyDepositCount++;
        totalFamilyDepositAmount += amount;
        cout << "Deposit of $" << amount << " to family account successful."
             << endl;
        cout << "New family account balance: $" << familyBalance << endl;
      } 
      else 
      {
        cout << "Invalid account type or family account not enabled." << endl;
      }
    }

    void withdraw(string accountType, double amount) 
    {
      if (amount <= 0) 
      {
        cout << "Invalid amount. Please enter a positive number." << endl;
        return;
      }

      cout << fixed << setprecision(2);
      if (accountType == "checking") 
      {
        if (checkingBalance >= amount) 
        {
          checkingBalance -= amount;
          checkingWithdrawalCount++;
          totalCheckingWithdrawalAmount += amount;
          cout << "Withdrawal of $" << amount
               << " from checking account successful." << endl;
          cout << "New checking balance: $" << checkingBalance << endl;
        } 
        else 
        {
          checkingOverdraftCharges += 25.0;
          cout << "Insufficient funds. Current balance: $" << checkingBalance
               << endl;
          cout << "Overdraft fee of $25 charged." << endl;
          cout << "Total overdraft charges: $" << checkingOverdraftCharges
               << endl;
        }
      } 
      else if (accountType == "savings") 
      {
        if (savingsBalance >= amount) 
        {
          savingsBalance -= amount;
          savingsWithdrawalCount++;
          totalSavingsWithdrawalAmount += amount;
          cout << "Withdrawal of $" << amount
               << " from savings account successful." << endl;
          cout << "New savings balance: $" << savingsBalance << endl;
        } 
        else 
        {
          savingsOverdraftCharges += 25.0;
          cout << "Insufficient funds. Current balance: $" << savingsBalance
               << endl;
          cout << "Overdraft fee of $25 charged." << endl;
          cout << "Total overdraft charges: $" << savingsOverdraftCharges
               << endl;
        }
      } 
      else if (accountType == "family" && isFamily) 
      {
        if (familyBalance >= amount) 
        {
          familyBalance -= amount;
          familyWithdrawalCount++;
          totalFamilyWithdrawalAmount += amount;
          cout << "Withdrawal of $" << amount
               << " from family account successful." << endl;
          cout << "New family account balance: $" << familyBalance << endl;
        } 
        else 
        {
          familyOverdraftCharges += 25.0;
          cout << "Insufficient funds. Current balance: $" << familyBalance
               << endl;
          cout << "Overdraft fee of $25 charged." << endl;
          cout << "Total overdraft charges: $" << familyOverdraftCharges
               << endl;
        }
      } 
      else 
      {
        cout << "Please choose one of the three accounts options" << endl;
      }
    }

    void displayInfo() const 
    {
      cout << fixed << setprecision(2);
      cout << "\nCustomer Information:" << endl;
      cout << "Name: " << customerName << endl;
      cout << "Account Number: " << AcctNumber << endl;
      cout << "Checking Balance: $" << checkingBalance << endl;
      cout << "Savings Balance: $" << savingsBalance << endl;

      if (isFamily) 
      {
        cout << "\nFamily Account Information:" << endl;
        cout << "Family Account Balance: $" << familyBalance << endl;
      }
    }

    void setName(string name) 
    { 
        customerName = name; 
    }
    void setAcctNumber(long long int num) 
    { 
        AcctNumber = num; 
    }
    void setIsFamily(bool family) 
    { isFamily = family; }
    bool getIsFamily() const 
    { 
        return isFamily; 
    }

    void setFamilyMember(string name) {
      if (numFamilyMembers < MAX_FAMILY_MEMBERS) 
      {
        familyMembers[numFamilyMembers++] = name;
      } 
      else 
      {
        cout << "Maximum number of family members reached." << endl;
      }
    }
  };

  Customer customers[MAX_CUSTOMERS];

  Bank() 
  {
    BankName = "SMART BANK";
    numCustomers = 0;
  }

  void Get_Info() 
  {
    if (numCustomers >= MAX_CUSTOMERS) 
    {
      cout << "Maximum number of customers reached." << endl;
      return;
    }

    string name;
    char familyChoice;
    long long int acct_num;
    int addFam;

    cout << "Please enter your name: ";
    getline(cin, name);
    customers[numCustomers].setName(name);

    cout << "Please enter account number: ";
    cin >> acct_num;
    customers[numCustomers].setAcctNumber(acct_num);

    cout << "Would you like to open a family account? (y/n): ";
    cin >> familyChoice;
    customers[numCustomers].setIsFamily(tolower(familyChoice) == 'y');

    if (customers[numCustomers].getIsFamily()) 
    {
      cout << "How many family members would you like to add (max = 5): ";
      cin >> addFam;
      addFam = min(addFam, MAX_FAMILY_MEMBERS);

      for (int i = 0; i < addFam; i++) 
      {
        string familyMemberName;
        cout << "Enter family member name: ";
        cin.get();
        getline(cin, familyMemberName);
        customers[numCustomers].setFamilyMember(familyMemberName);
      }
    }

    cout << fixed << setprecision(2);
    cout << "\nAccount created successfully!!!" << endl;
    customers[numCustomers].displayInfo();
    processTransaction(customers[numCustomers]);

    numCustomers++;
  }

  void processTransaction(Customer &customer) 
  {
    char choice;
    string accountType;
    double amount;

    do 
    {
      cout << "\nWould you like to make a transaction? (yes/no): ";
      cin >> choice;
      if (tolower(choice) != 'y')
        break;

      int accountChoice;
      if (customer.getIsFamily()) 
      {
        cout << "\nSelect account type:" << endl;
        cout << "1. Checking" << endl;
        cout << "2. Savings" << endl;
        cout << "3. Family" << endl;
        cout << "Enter choice (1-3): ";
        cin >> accountChoice;

        switch (accountChoice) 
        {
        case 1:
          accountType = "checking";
          break;
        case 2:
          accountType = "savings";
          break;
        case 3:
          accountType = "family";
          break;
        default:
          cout << "You have not selected one of our banking options." << endl;
          continue;
        }
      } 
      else 
      {
        cout << "\nSelect account type:" << endl;
        cout << "1. Checking" << endl;
        cout << "2. Savings" << endl;
        cout << "Enter choice (1-2): ";
        cin >> accountChoice;

        if (accountChoice == 1) 
        {
          accountType = "checking";
        } 
        else if (accountChoice == 2) 
        {
          accountType = "savings";
        } 
        else 
        {
          cout << "You haven't selected one of our banking options." << endl;
          continue;
        }
      }

      int transactionChoice;
      cout << "\nSelect transaction operation type:" << endl;
      cout << "1. Deposit" << endl;
      cout << "2. Withdraw" << endl;
      cout << "Enter choice (1-2): ";
      cin >> transactionChoice;

      cout << "Enter amount: $";
      cin >> amount;

      if (transactionChoice == 1) 
      {
        customer.deposit(accountType, amount);
      } 
      else 
      {
        customer.withdraw(accountType, amount);
      }

    } while (true);
  }

  string getBankName() const 
  { 
    return BankName; 
  }
  void setBankName(string name) 
  { 
    BankName = name; 
  }

  ~Bank(){};
};

int main() 
{
  Bank bank;
  cout << setw(35) << "WELCOME TO " << bank.getBankName() << endl;
  cout << endl;
  cout << setw(30) << "You can create an account," << endl;
  cout << setw(35) << "make deposits, and withdrawals." << endl;
  cout << setw(38) << "Family accounts are available too!" << endl;
  cout << "____________________________________________________________________"
          "_\n"
       << endl;
  bank.Get_Info();

  cout << "\nThank you for using " << bank.getBankName() << " services!"
       << endl;
  return 0;
}