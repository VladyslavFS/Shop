#include "goods.h"
#include <iostream>

Goods::Goods(const string& name, const string& date, double price, int quantity, int invoiceNumber) {
    this->name = name;
    this->date = date;
    this->price = price;
    this->quantity = quantity;
    this->invoiceNumber = invoiceNumber;
}
Goods::Goods() {
    name = "iceCream";
}

void Goods::changePrice(double newPrice) {
    this->price = newPrice;
}

void Goods::increaseQuantity(int amount) {
    quantity += amount;
}

void Goods::decreaseQuantity(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
    }
    else {
        cerr << "Error: Not enough quantity available." << endl;
    }
}

double Goods::calculateTotal() const {
    return price * quantity;
}

string Goods::toString() const {
    return "Name: " + name + ", Date: " + date + ", Price: " + to_string(price) +
        ", Quantity: " + to_string(quantity) + ", Invoice Number: " + to_string(invoiceNumber);
}
