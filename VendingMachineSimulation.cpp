#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

// VendingMachineItem class declaration
class VendingMachineItem 
{
public:
    string item_name;
    double sell_price;
    int max_quantity;
    double cost_price;

    VendingMachineItem(string item_name, double sell_price, int max_quantity);  // VendingMachineItem constructor declaration
};

// VendingMachine class declaration
class VendingMachine 
{
public:
    vector<VendingMachineItem> items;
    int nickels, dimes, quarters, oneDollarBills, fiveDollarBills;
    bool isOn;
    time_t startTime;
    static const int MAX_CAP = 30;

    VendingMachine();   // Vending Machine Constructor declaration

    // The 20 Function prototypes of the Vending Machine Class
    void displayMenu();
    bool checkIfOn();
    void turnOn();
    void refillItems();
    void refillCoinsinContainer();
    void removeExcessCoins();
    void selectItem();
    double acceptCoins();
    bool checkCoinValidity(char payment);
    double addCoin(char payment);
    void checkPriceAndDispense(VendingMachineItem& item, double amount_paid);
    void returnChange(double change);
    vector<double> calculateHourlySalesPerItem();
    vector<double> calculateDailySalesPerItem();
    double calculateTotalSales();
    double computeTotalCost();
    double computeLaborCost();
    double computeOverhead();
    double computeProfit();
    void displaySalesRecord();
    void run();
};

// VendingMachineItem class constructor implementation/initialization
VendingMachineItem::VendingMachineItem(string item_name, double sell_price, int max_quantity) 
{
    this->item_name = item_name;
    this->sell_price = sell_price;
    this->max_quantity = max_quantity;
    this->cost_price = sell_price * 0.35;
}

// VendingMachine class constructor implementation/initialization
VendingMachine::VendingMachine() //empty constructor just like it was declared
{
    this->nickels = 20;
    this->dimes = 20;
    this->quarters = 20;
    this->oneDollarBills = 20;
    this->fiveDollarBills = 20;
    this->isOn = false;
    this->items = { VendingMachineItem("Coke", 0.95, 30), VendingMachineItem("Doritos", 0.75, 30), VendingMachineItem("Snickers", 0.55, 30), VendingMachineItem("Chex Mix", 0.60, 30), VendingMachineItem("Pepsi", 0.90, 30)};
}

void VendingMachine::displayMenu() {
    cout << endl;
    cout << right << setw(35) << "VENDING MACHINE ITEMS MENU" << endl;
    cout << right << setw(45) << "--------------------------------------------" << endl;
    int index;
    for (index = 0; index < items.size(); index++) {
        cout << index + 1 << ". " << items[index].item_name << ": $" << fixed << setprecision(2) << items[index].sell_price << endl;
    }
}

bool VendingMachine::checkIfOn() {
    return isOn;
}


void VendingMachine::turnOn() 
{
    if (!isOn) 
    {
        isOn = true;
        startTime = time(nullptr);
        cout << "Vending machine starting now...." << endl;
    }
}

void VendingMachine::refillItems() 
{
    int index;
    for (index = 0; index < items.size(); index++) 
    {
        if (items[index].max_quantity < 5) 
        {
            items[index].max_quantity = 30;
        }
    }
}


void VendingMachine::refillCoinsinContainer() 
{
    if (nickels < 20) 
    {
        nickels = 20;
    }
    if (dimes < 20) 
    {
        dimes = 20;
    }
    if (quarters < 20) 
    {
        quarters = 20;
    }
}

void VendingMachine::removeExcessCoins() {
    if (nickels > 100) 
    {
        nickels = 20;
    }
    if (dimes > 100) 
    {
        dimes = 20;
    }
    if (quarters > 100) 
    {
        quarters = 20;
    }
    if (oneDollarBills > 100) 
    {
        oneDollarBills = 20;
    }
    if (fiveDollarBills > 60) 
    {
        fiveDollarBills = 20;
    }
}

void VendingMachine::selectItem() {
    displayMenu();
    int choice;
    cout << "Enter the number of the item you want to purchase: ";
    cin >> choice;
    
    cout << endl;
    if (choice < 1 || choice > static_cast<int>(items.size())) {
        cout << "Invalid choice.\n";
        return;
    }
    
    VendingMachineItem& selectedItem = items[choice - 1];
    double amount = acceptCoins();
    checkPriceAndDispense(selectedItem, amount);
}
double VendingMachine::acceptCoins() {
    double total = 0;
    char choice;
    do {
        cout << "This machine accepts Nickels, Dimes, Quarters, One dollar bills, and Five dollar Bills\n";
        cout << "Please enter one of the following: N, D, Q, O, F, C to Complete Purchase or R to view Records: ";
        cin >> choice;
        choice = toupper(choice);
        
        if (checkCoinValidity(choice)) 
        {
            total += addCoin(choice);
        } 
        else if (choice != 'C') 
        {
            cout << "Invalid input." << endl;
        }
        cout << "Current total: $" << fixed << setprecision(2) << total << endl;
        cout << endl;
    } while (choice != 'C');
    return total;
}


bool VendingMachine::checkCoinValidity(char payment) {
    if (payment == 'N' || payment == 'D' || payment == 'Q' || payment == 'O' || payment == 'F') 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

double VendingMachine::addCoin(char payment) {
    if (payment == 'N') 
    {
        nickels++;
        return 0.05;
    }
    else if (payment == 'D') 
    {
        dimes++;
        return 0.10;
    }
    else if (payment == 'Q') 
    {
        quarters++;
        return 0.25;
    }
    else if (payment == 'O')
    {
        oneDollarBills++;
        return 1.00;
    }
    else if (payment == 'F') 
    {
        fiveDollarBills++;
        return 5.00;
    }
    else {
        return 0;
    }
}


void VendingMachine::checkPriceAndDispense(VendingMachineItem& item, double amount_paid) {
    if (amount_paid < item.sell_price) 
    {
        cout << "Insufficient funds. Returning $" << fixed << setprecision(2) << amount_paid << "\n";
    } 
    else 
    {
        item.max_quantity--;
        cout << "Dispensing " << item.item_name << "." << endl;
        if (amount_paid > item.sell_price) {
            returnChange(amount_paid - item.sell_price);
        }
    }
}

void VendingMachine::returnChange(double change) {
    cout << "Returning change: $" << fixed << setprecision(2) << change << "\n";
    cout << endl;
}

vector<double> VendingMachine::calculateHourlySalesPerItem() 
{
    vector<double> hourlySales;
    int index;
    for (index = 0; index < items.size(); index++) 
    {
        hourlySales.push_back((MAX_CAP - items[index].max_quantity) * items[index].sell_price / 6.0);
    }
    return hourlySales;
}

vector<double> VendingMachine::calculateDailySalesPerItem() 
{
    vector<double> dailySales;
    int index;
    for (index = 0; index < items.size(); index++) 
    {
        dailySales.push_back((MAX_CAP - items[index].max_quantity) * items[index].sell_price);
    }
    return dailySales;
}


double VendingMachine::calculateTotalSales() 
{
    double totalSales = 0;
    int index;
    for (index = 0; index < items.size() ; index++) 
    {
        totalSales += (MAX_CAP - items[index].max_quantity) * items[index].sell_price;
    }
    return totalSales;
}

double VendingMachine::computeTotalCost() 
{
    double totalCost = 0;
    int index;
    for (index = 0; index < items.size(); index++) {
        totalCost += (MAX_CAP - items[index].max_quantity) * items[index].cost_price;
    }
    return totalCost;
}


double VendingMachine::computeLaborCost() 
{
    double tot_sale, laborCost;
    tot_sale = calculateTotalSales();
    laborCost = tot_sale * 0.25;
    return laborCost;
}


double VendingMachine::computeOverhead() 
{
    double tot_sale, overHead;
    tot_sale = calculateTotalSales();
    overHead = tot_sale * 0.05;
    return overHead;
}


double VendingMachine::computeProfit() 
{
    double profit;
    profit = calculateTotalSales() - computeTotalCost() - computeLaborCost() - computeOverhead();
    return profit;
}

void VendingMachine::displaySalesRecord() 
{
    cout << endl;
    cout << "Vending Machine Daily Transactions Record:\n";
    vector<double> dailySales = calculateDailySalesPerItem();
    int index;
    for (index = 0; index < items.size(); index++) 
    {
        cout << "Total daily sales for " << items[index].item_name << " = $" << fixed << setprecision(2) << dailySales[index] << endl;
    }
    
    cout << endl;
    cout << "Total sales for all Items = $" << calculateTotalSales() << endl;
    cout << "Total cost of all items = $" << computeTotalCost() << endl;
    cout << "Daily Labor cost = $" << computeLaborCost() << endl;
    cout << "Daily Overhead = $" << computeOverhead() << endl;
    cout << "Daily Profit = $" << computeProfit() << endl;
}

void VendingMachine::run() 
{
    if (!isOn) 
    {
        cout << "Vending machine is off. Turn it on first.\n";
        return;
    }

    time_t currentTime = time(nullptr);
    if (difftime(currentTime, startTime) >= 6 * 3600) 
    {
        cout << "Vending machine has been running for 6 hours. Machine is shutting down in 3.2.1.\n";
        isOn = false;
        displaySalesRecord();
        return;
    }

    int choice;
    do {
        cout << endl;
        cout << "Press 2 to purchase an item of your choice, 1 to view Records, or 0 to exit: ";
        cin >> choice;
        if (choice == 2) 
        {
            selectItem();
        }
        else if (choice == 1) 
        {
            displaySalesRecord();
        }
        else if (choice == 0) 
        {
            isOn = false; 
            cout << "Goodbye..." << endl;
        }
        else 
        {
            cout << "Invalid Choice!\n";
            cout << "Please press one of the provided buttons" << endl;
        }
    } while (isOn);
}

int main() {
    VendingMachine vending_machine;
    char choice;

    do {
        cout << "Do you want to turn on the vending machine? (Y for Yes): ";
        cin >> choice;
        if (toupper(choice) == 'Y') {
            vending_machine.turnOn();
            vending_machine.run();
        }
    } while (toupper(choice) != 'Y');

    return 0;
}