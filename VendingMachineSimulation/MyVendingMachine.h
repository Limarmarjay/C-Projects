#pragma once
#include "VendingMachineItem.h"
#include <iostream>
#include <string>
using namespace std;

class MyVendingMachine {
public:
    Coke* coke;
    Doritos* doritos;
    Snickers* snickers;
    ChexMix* chexmix;
    Pepsi* pepsi;
public:
    MyVendingMachine();
    ~MyVendingMachine();
    
    bool is_vending_machine_on;
    int dimes_in_container, nickels_in_container, quarters_in_container, 
        one_dollar_bills_in_container, five_dollar_bills_in_container;
    int total_sales, hours;
    int amount_paid;
    
    // Methods for Vending Machine
    void refill();
    void displayMenuOptions();
    // void displayPaymentOptions();
    void displayPaidAmount(double);
    bool isOn();
    void turnOn();
    void selectItem(const std::string&);
    void acceptPayment(double, double);
    bool checkCoinValidity(); 
    double returnChange(double);
    double computeChange(double, double);
    void handleItemRecords();
    double computeTotalSalesOfAllItems();
    double computeTotalCostOfAllItems();
    double computeTotalProfit();
    double computeTotalLaborCost();
    double computeTotalOverhead();
    void addQuartersToContainer();
    void addDimesToContainer();
    void addNickelsToContainer();
    void addOneDollarToContainer();
    void addFiveDollarsToContainer();
    
    void run();
};