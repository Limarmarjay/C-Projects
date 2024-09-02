#include "MyVendingMachine.h"
#include "VendingMachineItem.h"
// #include <windows.h>
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

MyVendingMachine::MyVendingMachine() 
    : is_vending_machine_on(false), total_sales(0), hours(0), amount_paid(0),
      dimes_in_container(20), nickels_in_container(20), quarters_in_container(20),
      one_dollar_bills_in_container(20), five_dollar_bills_in_container(20) {
    coke = new Coke();
    doritos = new Doritos();
    snickers = new Snickers();
    chexmix = new ChexMix();
    pepsi = new Pepsi();
}

void MyVendingMachine::refill() {
    coke->refillEachItem();
    doritos->refillEachItem();
    snickers->refillEachItem();
    chexmix->refillEachItem();
    pepsi->refillEachItem();
}

void MyVendingMachine::displayMenuOptions() {
    this->turnOn();
    
    while (hours < 6) {
        cout << setw(20) << "Welcome" << endl;
        cout << "----------------------------------------" << endl;
        cout << setw(30) << "Make an Item Selection" << endl;
        cout << left << setw(15) << "Item Name" << setw(30) << "Price" << endl;
        cout << "----------------------------------------" << endl;
        cout << left << setw(5) << "A" << setw(15) << "Coke" << "$" << setw(7) << fixed << setprecision(2) << coke->sell_price << endl;
        cout << left << setw(5) << "B" << setw(15) << "Doritos" << "$" << setw(7) << fixed << setprecision(2) << doritos->sell_price << endl;
        cout << left << setw(5) << "C" << setw(15) << "Snickers" << "$" << setw(7) << fixed << setprecision(2) << snickers->sell_price << endl;
        cout << left << setw(5) << "D" << setw(15) << "Chex Mix" << "$" << setw(7) << fixed << setprecision(2) << chexmix->sell_price << endl;
        cout << left << setw(5) << "E" << setw(15) << "Pepsi" << "$" << setw(7) << fixed << setprecision(2) << pepsi->sell_price << endl;
        
        string selection = getValidInput();
        selectItem(selection);
        hours++;
    }
}

string MyVendingMachine::getValidInput() {
    string user_choice;
    bool valid = false;

    do {
        cout << "Please enter any option of your choice from A-E: ";
        getline(cin, user_choice);

        if (!user_choice.empty()) {
            char upper = toupper(user_choice[0]);
            if (upper >= 'A' && upper <= 'E') {
                valid = true;
                return string(1, upper);  // Return uppercase single-character string
            } else {
                cout << "Invalid input. Please enter a letter between A and E." << endl;
            }
        } else {
            cout << "Empty input. Please enter a letter." << endl;
        }

        if (!valid) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!valid);

    return "";
}

void MyVendingMachine::displayPaidAmount(double amount) {
    cout << endl;
    cout << "You paid: $" << fixed << setprecision(2) << amount << endl;
    cout << "Thank you for your Purchase!" << endl;
}

bool MyVendingMachine::isOn() {
    return is_vending_machine_on;
}

void MyVendingMachine::turnOn() {
    if (!this->isOn()) {
        cout << "Vending Machine is Starting now..Hold on" << endl;
        this->is_vending_machine_on = true;
    }
    // Sleep(5000);
}

void MyVendingMachine::selectItem(const string& item) {
    cout << endl;
    cout << "This machine accepts quarters, dimes, nickels, $1 bills, and $5 bills" << endl;
    cout << "Please enter your payment amount: ";
    double customer_pay;
    cin >> customer_pay;
    
    if (item == "A") {
        cout << "You selected Coke" << endl;
        acceptPayment(coke->sell_price, customer_pay);
        coke->NumUnitsSold();
    }
    else if (item == "B") {
        cout << "You selected Doritos" << endl;
        acceptPayment(doritos->sell_price, customer_pay);
        doritos->NumUnitsSold();
    }
    else if (item == "C") {
        cout << "You selected Snickers" << endl;
        acceptPayment(snickers->sell_price, customer_pay);
        snickers->NumUnitsSold();
    }
    else if (item == "D") {
        cout << "You selected Chex Mix" << endl;
        acceptPayment(chexmix->sell_price, customer_pay);
        chexmix->NumUnitsSold();
    }
    else if (item == "E") {
        cout << "You selected Pepsi" << endl;
        acceptPayment(pepsi->sell_price, customer_pay);
        pepsi->NumUnitsSold();
    }
    else {
        cout << "Invalid selection. Please try again." << endl;
    }
}

void MyVendingMachine::acceptPayment(double price, double initial_payment) {
    this->amount_paid = initial_payment;
    bool transaction_complete = false;
    cout << endl;
    while (!transaction_complete) {
        if (amount_paid >= price) {
            double change = computeChange(amount_paid, price);
            if (change > 0) {
                if (returnChange(change)) {
                    cout << "Transaction completed successfully." << endl;
                    cout << endl;
                    total_sales += price;
                    transaction_complete = true;
                } else {
                    cout << "Unable to provide change. Transaction cancelled." << endl;
                    returnChange(amount_paid);  // Return all money inserted
                    transaction_complete = true;
                }
            } else {
                cout << "Transaction completed successfully." << endl;
                total_sales += price;
                transaction_complete = true;
            }
        } else {
            cout << endl;
            cout << "Current amount: $" << fixed << setprecision(2) << amount_paid << endl;
            cout << "Amount needed: $" << fixed << setprecision(2) << price - amount_paid << endl;
            cout << "Enter q (add quarters), d (add dimes), n (add nickels), o (add $1) or f (add $5) bills, c to cancel: ";
            
            char payment_type;
            cin >> payment_type;

            if (payment_type == 'q') {
                addQuartersToContainer();
            } else if (payment_type == 'd') {
                addDimesToContainer();
            } else if (payment_type == 'n') {
                addNickelsToContainer();
            } else if (payment_type == 'o') {
                addOneDollarToContainer();
            } else if (payment_type == 'f') {
                addFiveDollarsToContainer();
            } else if (payment_type == 'c') {
                cout << "Transaction cancelled." << endl;
                returnChange(amount_paid);  // Return all money inserted
                transaction_complete = true;
            } else {
                cout << "Invalid option. Try again." << endl;
            }
        }
    }
}


bool MyVendingMachine::checkCoinValidity() {
    return true;
}

double MyVendingMachine::returnChange(double change) {
    cout << "Returning change: $" << fixed << setprecision(2) << change << endl;
    return change;
}

double MyVendingMachine::computeChange(double payment, double sell_price) {
    double change = payment - sell_price;
    return change;
}

void MyVendingMachine::handleItemRecords() {
    double totalSales = computeTotalSalesOfAllItems();
    cout << "Total Sales for Coke: $" << fixed << setprecision(2) << coke->total_sales << endl;
    cout << "Total Sales for Doritos: $" << doritos->total_sales << endl;
    cout << "Total Sales for Snickers: $" << snickers->total_sales << endl;
    cout << "Total Sales for Chex Mix: $" << chexmix->total_sales << endl;
    cout << "Total Sales for Pepsi: $" << pepsi->total_sales << endl;
    cout << "Total Sales Combined: $" << totalSales << endl;
    
    double totalCost = computeTotalCostOfAllItems();
    cout << "Total Cost of all items: $" << totalCost << endl;
    
    double totalProfit = computeTotalProfit();
    cout << "Profit: $" << totalProfit << endl;
}

double MyVendingMachine::computeTotalSalesOfAllItems() {
    coke->total_sales = coke->sell_price * coke->num_units_sold_per_item * hours;
    doritos->total_sales = doritos->sell_price * doritos->num_units_sold_per_item * hours;
    snickers->total_sales = snickers->sell_price * snickers->num_units_sold_per_item * hours;
    chexmix->total_sales = chexmix->sell_price * chexmix->num_units_sold_per_item * hours;
    pepsi->total_sales = pepsi->sell_price * pepsi->num_units_sold_per_item * hours;
    return coke->total_sales + doritos->total_sales + snickers->total_sales + chexmix->total_sales + pepsi->total_sales;
}

double MyVendingMachine::computeTotalCostOfAllItems() {
    double total_cost = coke->cost_price + doritos->cost_price
		+ chexmix->cost_price + snickers->cost_price + pepsi->cost_price;
	return total_cost;
}

double MyVendingMachine::computeTotalProfit() {
    return computeTotalSalesOfAllItems() - computeTotalCostOfAllItems() - computeTotalLaborCost() - computeTotalOverhead();
}

double MyVendingMachine::computeTotalLaborCost() {
    double total_labor_cost = 0;
    total_labor_cost = computeTotalSalesOfAllItems() * 0.25;
    return total_labor_cost;
}

double MyVendingMachine::computeTotalOverhead() {
    double total_overhead = 0;
    total_overhead = computeTotalSalesOfAllItems() * 0.25;
    return total_overhead;
}

void MyVendingMachine::addQuartersToContainer() {
    int newQuarters;
    cout << "Please enter the number of quarters you want to add to the container: ";
    cin >> newQuarters;
    if (quarters_in_container + newQuarters <= 100) {
        quarters_in_container += newQuarters;
    } 
    else {
        cout << "Container limit reached for quarters. Resetting to 20." << endl;
        quarters_in_container = 20;
    }
    this->amount_paid += newQuarters * 0.25;
}

void MyVendingMachine::addDimesToContainer() {
    int newDimes;
    cout << "Please enter the number of dimes you want to add to the container: ";
    cin >> newDimes;
    if (dimes_in_container + newDimes <= 100) {
        dimes_in_container += newDimes;
    } 
    else {
        cout << "Container limit reached for dimes. Resetting to 20." << endl;
        dimes_in_container = 20;
    }
    this->amount_paid += newDimes * 0.10;
}

void MyVendingMachine::addNickelsToContainer() {
    int newNickels;
    cout << "Please enter the number of nickels you want to add to the container: ";
    cin >> newNickels;
    if (nickels_in_container + newNickels <= 100) {
        nickels_in_container += newNickels;
    } 
    else {
        cout << "Container limit reached for nickels. Resetting to 20." << endl;
        nickels_in_container = 20;
    }
    this->amount_paid += newNickels * 0.05;
}

void MyVendingMachine::addOneDollarToContainer() {
    int newOneDollarbill;
	cout << "Please enter the number of dollars you wanna add to container: ";
	cin >> newOneDollarbill;
	if (one_dollar_bills_in_container <= 100)
		one_dollar_bills_in_container += newOneDollarbill;
	else
		one_dollar_bills_in_container = 20;
	this->amount_paid += newOneDollarbill * 1.00;
}

void MyVendingMachine::addFiveDollarsToContainer() {
    int newFiveDollarbill = 1;
	cout << "Please enter the number of five dollar bills you wanna add to container: ";
	cin >> newFiveDollarbill;
	if (five_dollar_bills_in_container <= 60)
		five_dollar_bills_in_container += newFiveDollarbill;
	else
		five_dollar_bills_in_container = 20;
	this->amount_paid += newFiveDollarbill * 5.00;
}

void MyVendingMachine::run() {
    displayMenuOptions();
}