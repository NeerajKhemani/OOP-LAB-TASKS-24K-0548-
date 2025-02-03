#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string ProductName;
    int ProductId;
    double Price;
    int StockQuantity;

    Product(string name, int id, double price, int stock)
        : ProductName(name), ProductId(id), Price(price), StockQuantity(stock) {}

    void SellProduct(int quantity) {
        if (StockQuantity >= quantity) {
            StockQuantity -= quantity;
        } else {
            cout << "Insufficient stock." << endl;
        }
    }
    void RestockProduct(int quantity) {
        StockQuantity += quantity;
    }

    void DisplayProductInfo() {
        cout << "Product Name: " << ProductName << endl;
        cout << "Product ID: " << ProductId << endl;
        cout << "Price: " << Price << endl;
        cout << "Stock Quantity: " << StockQuantity << endl;
    }
};

int main() {
    Product product1("Laptop", 565, 4313, 151);
    product1.DisplayProductInfo();
    product1.SellProduct(10);
    product1.DisplayProductInfo();
    product1.RestockProduct(20);
    product1.DisplayProductInfo();
    return 0;
}
