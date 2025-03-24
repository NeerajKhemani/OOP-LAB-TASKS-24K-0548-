#include <iostream>
#include <cstring>

class Product {
protected:
    char productID[20];
    double price;
public:
    Product(const char* id, double p) {
        strcpy(productID, id);
        price = p;
    }
    virtual double calculatePrice() = 0;
    double getPrice() { return price; }
};

class Electronics : public Product {
public:
    Electronics(const char* id, double p) : Product(id, p) {}
    double calculatePrice() {
        return price * 1.15;
    }
};

class Clothing : public Product {
public:
    Clothing(const char* id, double p) : Product(id, p) {}
    double calculatePrice() {
        return price * 1.05;
    }
};

class ShoppingCart {
private:
    Product* items[10];
    int itemCount;
public:
    ShoppingCart() { itemCount = 0; }
    void addItem(Product* item) {
        if (itemCount < 10) {
            items[itemCount++] = item;
        }
    }
    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i]->calculatePrice();
        }
        return total;
    }
    ShoppingCart operator+(ShoppingCart& other) {
        ShoppingCart newCart;
        for (int i = 0; i < itemCount; i++) {
            newCart.addItem(items[i]);
        }
        for (int i = 0; i < other.itemCount; i++) {
            newCart.addItem(other.items[i]);
        }
        return newCart;
    }
    ShoppingCart operator-(Product* item) {
        ShoppingCart newCart;
        for (int i = 0; i < itemCount; i++) {
            if (items[i] != item) {
                newCart.addItem(items[i]);
            }
        }
        return newCart;
    }
    ShoppingCart operator*(double discount) {
        ShoppingCart newCart;
        for (int i = 0; i < itemCount; i++) {
            double discountedPrice = items[i]->calculatePrice() * (1 - discount);
            newCart.addItem(new Electronics("Discounted", discountedPrice));
        }
        return newCart;
    }
    ShoppingCart operator/(int users) {
        ShoppingCart newCart;
        double splitAmount = calculateTotal() / users;
        newCart.addItem(new Electronics("Split", splitAmount));
        return newCart;
    }
};

int main() {
    Electronics e1("E1001", 1000);
    Clothing c1("C2001", 500);
    
    ShoppingCart cart1, cart2;
    cart1.addItem(&e1);
    cart2.addItem(&c1);
    
    ShoppingCart mergedCart = cart1 + cart2;
    ShoppingCart discountedCart = mergedCart * 0.10;
    ShoppingCart splitCart = mergedCart / 2;
    
    std::cout << "Total Price: " << mergedCart.calculateTotal() << "\n";
    std::cout << "Discounted Price: " << discountedCart.calculateTotal() << "\n";
    std::cout << "Split Price per user: " << splitCart.calculateTotal() << "\n";
    
    return 0;
}