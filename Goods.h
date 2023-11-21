#ifndef GOODS_H
#define GOODS_H

#include <string>
using namespace std;

class Goods {
public:
    Goods(const string& name, const string& date, double price, int quantity, int invoiceNumber);
    Goods();

    void changePrice(double newPrice);
    void increaseQuantity(int amount);
    void decreaseQuantity(int amount);
    double calculateTotal() const;
    string toString() const;

private:
    string name;
    string date;
    double price;
    int quantity;
    int invoiceNumber;
};

#endif
