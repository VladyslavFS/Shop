// main.cpp

#include "goods.h"
#include <iostream>
#include <map>

using namespace std;

int showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Change Price\n";
    cout << "2. Increase Quantity\n";
    cout << "3. Decrease Quantity\n";
    cout << "4. Calculate Total\n";
    cout << "5. Show Goods Information\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    return choice;
}

int main() {
    map<int, Goods> goodsMap;
    Goods a = Goods("Item1", "2023-01-01", 10.5, 50, 101);

    goodsMap.emplace(1, a);
    goodsMap.emplace(2, Goods());

    bool exit = false;
    while (!exit) {
        int choice = showMenu();

        switch (choice) {
        case 1: {
            int number;
            double newPrice;
            cout << "Enter Invoice Number: ";
            cin >> number;
            cout << "Enter New Price: ";
            cin >> newPrice;
            goodsMap[number].changePrice(newPrice);
            break;
        }
        case 2: {
            int number, amount;
            cout << "Enter Invoice Number: ";
            cin >> number;
            cout << "Enter Quantity to Increase: ";
            cin >> amount;
            goodsMap[number].increaseQuantity(amount);
            break;
        }
        case 3: {
            int number, amount;
            cout << "Enter Invoice Number: ";
            cin >> number;
            cout << "Enter Quantity to Decrease: ";
            cin >> amount;
            goodsMap[number].decreaseQuantity(amount);
            break;
        }
        case 4: {
            int number;
            cout << "Enter Invoice Number: ";
            cin >> number;
            cout << "Total: " << goodsMap[number].calculateTotal() << endl;
            break;
        }
        case 5: {
            for (const auto& entry : goodsMap) {
                cout << "Invoice Number: " << entry.first << ", " << entry.second.toString() << endl;
            }
            break;
        }
        case 6:
            exit = true;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
