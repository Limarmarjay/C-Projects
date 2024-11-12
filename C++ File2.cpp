#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Bank 
{
protected:
    string Name;
    string Address;
    
public:
    Bank(string Name = "", string Address = "") 
    {
        this->Name = Name;
        this->Address = Address;
    }
    
    virtual void Get_Info() 
    {
        cout << "Please enter Bank name: ";
        cin >> this->Name;
        
        cout << "Please enter Bank address: ";
        cin >> this->Address;
    }
    
    virtual void Display_Info() const
    {
        cout << setw(8) << "Bank Name is: " << this->Name << "\n";
        cout << setw(8) << "Bank Address is: " << this->Address << "\n";
    }
    
    virtual ~Bank() {}; 
};

class Customer : public Bank 
{
private:
    double Savings_Balance;
    double Checking_Balance;
    double Deposit_Type;
    double Withdraw_Type;
    string Customer_Name;
    string Customer_Address;
    int Checking_Acct_Number;
    int Savings_Acct_Number;

public:
    Customer(double SB = 0, double CB = 0, double DT = 0, double WT = 0, string CN = "", string ADDY = "", int CAN = 0, int SAN = 0)
    {
        Savings_Balance = SB;
        Checking_Balance = CB;
        Deposit_Type = DT;
        Withdraw_Type = WT;
        Customer_Name = CN;
        Customer_Address = ADDY;
        Checking_Acct_Number = CAN;
        Savings_Acct_Number = SAN;
    }

    void Get_Info() override 
    {
        Bank::Get_Info();
        cout << "Please enter customer's savings account balance: ";
        cin >> Savings_Balance;
        
        cout << "Please enter customer's checking account balance: ";
        cin >> Checking_Balance;
        
        cout << "Please enter deposit type: ";
        cin >> Deposit_Type;
        
        cout << "Please enter Withdrawal type: ";
        cin >> Withdraw_Type;
        
        cout << "Please enter customer's name: ";
        cin >> Customer_Name;
        
        cout << "Please enter customer's address: ";
        cin >> Customer_Address;
        
        cout << "Please enter customer's checking account number: ";
        cin >> Checking_Acct_Number;
        
        cout << "Please enter customer's savings account number: ";
        cin >> Savings_Acct_Number;
    }

    void Get_Deposit() 
    {
        char indicate;
        double amount;
        cout << "Please enter the amount you are about to deposit: ";
        cin >> amount;
        cout << "Please type Y if you want to put the money in a savings account and N if you want to add it to a checking account: ";
        cin >> indicate;
        if (toupper(indicate) == 'Y') 
        {
            this->Savings_Balance += amount;
        }
        else if (toupper(indicate) == 'N') 
        {
            this->Checking_Balance += amount;
        }
        else 
        {
            cout << "Invalid Option!\n";
            cout << "Please try again...\n";
        }
    }

    void Get_Withdraw() 
    {
        char choice;
        double amt;
        cout << "Please enter withdrawal amount: ";
        cin >> amt;
        cout << "Please indicate if you have a checking account or savings account with us. Enter Y for checking and N for savings: ";
        cin >> choice;
        if (toupper(choice) == 'Y') 
        {
            if (amt <= this->Checking_Balance) 
            {
                this->Checking_Balance -= amt;
            }
            else 
            {
                cout << "Insufficient funds!!!\n";
            }
        }
        else if (toupper(choice) == 'N') 
        {
            if (amt <= this->Savings_Balance) 
            {
                this->Savings_Balance -= amt;
            }
            else 
            {
                cout << "Insufficient funds!!!\n";
            }
        }
    }

    void Get_Balance() const 
    {
        double total_Balance;
        total_Balance = this->Checking_Balance + this->Savings_Balance;
        cout << "The total balance is: " << total_Balance;
    }

    void Display_Info() override
    {
        Bank::Display_Info();
        cout << setw(8) << "Customer Name: " << Customer_Name << "\n";
        cout << setw(8) << "Customer Address: " << Customer_Address << "\n";
        cout << setw(8) << "Checking Account Number: " << Checking_Acct_Number << "\n";
        cout << setw(8) << "Savings Account Number: " << Savings_Acct_Number << "\n";
        cout << setw(8) << "Checking Balance: " << Checking_Balance << "\n";
        cout << setw(8) << "Savings Balance: " << Savings_Balance << "\n";
    }

    ~Customer() {};
};

int main() 
{
    int Num_Customers = 10;
    Customer customers[Num_Customers];

    for (int i = 0; i < Num_Customers; i++) 
    {
        cout << "Please enter your information: ";
        customers[i].Get_Info();
        cout << endl;
    }
    
    cout << setw(8) << "Find Banking information Below:\n";
    for (int i = 0; i < Num_Customers; i++) 
    {
        cout << setw(8) << "Customer Information:\n";
        customers[i].Display_Info();
        cout << endl;
        cout << "Customer total bank balance:\n";
        customers[i].Get_Balance();
    }
    return 0;
}
