#include "VendingMachineItem.h"
#include <iostream>

VendingMachineItem::VendingMachineItem(double price) : 
    sell_price(price), num_items(30), cost_price(0), 
    labor_cost(0), overhead(0), num_units_sold_per_item(0), total_sales(0.0) {}

bool VendingMachineItem::needsRefill() {
    return this->num_items < 5;
}

void VendingMachineItem::NumUnitsSold() {
    this->num_units_sold_per_item++;
    this->num_items--;
}

void VendingMachineItem::calculateTotalSalePerItem() {
    this->total_sales = this->sell_price * this->num_units_sold_per_item;
}

void VendingMachineItem::refillEachItem() {
    this->num_items = 30;
}

double VendingMachineItem::getTotalSales() {
    return this->total_sales;
}

Coke::Coke() : VendingMachineItem(0.95) {
    cost_price = 0.35 * sell_price;
    labor_cost = 0.25 * sell_price;
    overhead = 0.05 * sell_price;
}

// Doritos constructor
Doritos::Doritos() : VendingMachineItem(0.75) {
    cost_price = 0.35 * sell_price;
    labor_cost = 0.25 * sell_price;
    overhead = 0.05 * sell_price;
}

// Snickers constructor
Snickers::Snickers() : VendingMachineItem(0.55) {
    cost_price = 0.35 * sell_price;
    labor_cost = 0.25 * sell_price;
    overhead = 0.05 * sell_price;
}

// ChexMix constructor
ChexMix::ChexMix() : VendingMachineItem(0.60) {
    cost_price = 0.35 * sell_price;
    labor_cost = 0.25 * sell_price;
    overhead = 0.05 * sell_price;
}

// Pepsi constructor
Pepsi::Pepsi() : VendingMachineItem(0.90) {
    cost_price = 0.35 * sell_price;
    labor_cost = 0.25 * sell_price;
    overhead = 0.05 * sell_price;
}