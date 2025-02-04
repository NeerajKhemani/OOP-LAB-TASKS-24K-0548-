#include <iostream>
#include <iomanip>

using namespace std;

class StationeryShop {
private:
    string items[100];
    double prices[100];
    int itemCount;

public:
    StationeryShop() {
        itemCount = 0;
    }

    void addItem(string item, double price) {
        if (itemCount < 100) {
            items[itemCount] = item;
            prices[itemCount] = price;
            itemCount++;
            cout << "Item added successfully!\n";
        } else {
            cout << "Item list is full!\n";
        }
    }

    void fetchItems() {
        if (itemCount == 0) {
            cout << "No items available.\n";
            return;
        }
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }

    void editPrice(int index, double newPrice) {
        if (index >= 1 && index <= itemCount) {
            prices[index - 1] = newPrice;
            cout << "Price updated successfully!\n";
        } else {
            cout << "Invalid item number!\n";
        }
    }

    void viewAllItems() {
        if (itemCount == 0) {
            cout << "No items available.\n";
            return;
        }
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << " - " << fixed << setprecision(2) << prices[i] << " PKR" << endl;
        }
    }

    void generateReceipt() {
        if (itemCount == 0) {
            cout << "No items available to purchase.\n";
            return;
        }

        int numBought;
        cout << "Enter the number of items bought: ";
        cin >> numBought;

        string purchasedItems[100];
        int quantities[100];
        double total = 0;

        for (int i = 0; i < numBought; i++) {
            int itemIndex, quantity;
            cout << "Enter item number: ";
            cin >> itemIndex;
            if (itemIndex < 1 || itemIndex > itemCount) {
                cout << "Invalid item number!\n";
                i--;
                continue;
            }
            cout << "Enter quantity: ";
            cin >> quantity;

            purchasedItems[i] = items[itemIndex - 1];
            quantities[i] = quantity;
            total += prices[itemIndex - 1] * quantity;
        }

        cout << "\nReceipt:\n";
        for (int i = 0; i < numBought; i++) {
            cout << purchasedItems[i] << " x" << quantities[i] << " - " << fixed << setprecision(2) << (prices[i] * quantities[i]) << " PKR" << endl;
        }
        cout << "Total: " << fixed << setprecision(2) << total << " PKR\n";
    }
};

int main() {
    StationeryShop shop;
    int choice;

    while (true) {
        cout << "\n1. Add Item\n";
        cout << "2. Fetch Items\n";
        cout << "3. Edit Price\n";
        cout << "4. View All Items and Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            double price;
            cout << "Enter item name: ";
            cin >> ws;
            getline(cin, item);
            cout << "Enter item price: ";
            cin >> price;
            shop.addItem(item, price);
        } else if (choice == 2) {
            shop.fetchItems();
        } else if (choice == 3) {
            int index;
            double newPrice;
            cout << "Enter item number to edit price: ";
            cin >> index;
            cout << "Enter new price: ";
            cin >> newPrice;
            shop.editPrice(index, newPrice);
        } else if (choice == 4) {
            shop.viewAllItems();
        } else if (choice == 5) {
            shop.generateReceipt();
        } else if (choice == 6) {
            cout << "\nProgram exited successfully.\n" ;
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
