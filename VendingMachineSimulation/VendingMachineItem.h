#pragma once
#include <string>

class VendingMachineItem {
public:
    VendingMachineItem(double price = 0.0);
    virtual ~VendingMachineItem() = default;

    double sell_price;
    int num_items;
    double cost_price;
    double labor_cost;
    double overhead;
    double total_sales;
    int num_units_sold_per_item;  

    bool needsRefill();
    void NumUnitsSold();
    void calculateTotalSalePerItem();
    void refillEachItem();
    double getTotalSales();
};

class Coke : public VendingMachineItem {
public:
    Coke();
};

class Doritos : public VendingMachineItem {
public:
    Doritos();
};

class Snickers : public VendingMachineItem {
public:
    Snickers();
};

class ChexMix : public VendingMachineItem {
public:
    ChexMix();
};

class Pepsi : public VendingMachineItem {
public:
    Pepsi();
};
