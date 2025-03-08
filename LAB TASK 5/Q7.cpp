#include <iostream>
using namespace std;

class MenuItem
{
    string name;
    double price;

public:
    MenuItem() {}

    void setItem(string n, double p)
    {
        name = n;
        price = p;
    }

    string getName() const { return name; }
    double getPrice() const { return price; }

    void display() const
    {
        if (name != "")
            cout << name << ".....Rs." << price << endl;
    }
};

class Menu
{
    MenuItem items[30];
    int count;

public:
    Menu() : count(0) {}

    void addItems(int numItems)
    {
        if (count + numItems > 30)
        {
            cout << "Cannot add " << numItems << " items! Max limit reached.\n";
            return;
        }

        for (int i = 0; i < numItems; i++)
        {
            string name;
            double price;
            cout << "Enter food name: ";
            cin >> name;
            cout << "Enter price: ";
            cin >> price;

            items[count].setItem(name, price);
            count++;
        }
    }

    void removeItem(string itemName)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i].getName() == itemName)
            {
                for (int j = i; j < count - 1; j++)
                {
                    items[j] = items[j + 1];
                }
                count--;
                cout << itemName << " removed from menu.\n";
                return;
            }
        }
        cout << "Item not found in menu.\n";
    }

    void displayMenu() const
    {
        cout << "\n--- Menu ---\n";
        for (int i = 0; i < count; i++)
        {
            items[i].display();
        }
    }

    MenuItem *getItem(string itemName)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i].getName() == itemName)
                return &items[i];
        }
        return nullptr;
    }
};

class Payment
{
    double amount;

public:
    Payment(double amount) : amount(amount) {}

    void processPayment() const
    {
        cout << "Payment of Rs." << amount << " processed successfully!\n";
    }
};

class Order
{
    MenuItem **orderedItems;
    int itemCount;
    double totalAmount;
    Payment *payment;

public:
    Order() : itemCount(0), totalAmount(0.0), payment(nullptr)
    {
        orderedItems = new MenuItem *[30];
    }

    ~Order()
    {
        delete[] orderedItems;
        delete payment;
    }

    void addItem(MenuItem *item)
    {
        if (itemCount < 30)
        {
            orderedItems[itemCount] = item;
            totalAmount += item->getPrice();
            itemCount++;
        }
        else
        {
            cout << "Cannot add more items to the order.\n";
        }
    }

    void displayOrder() const
    {
        cout << "\n--- Order Details ---\n";
        for (int i = 0; i < itemCount; i++)
        {
            orderedItems[i]->display();
        }
        cout << "Total: Rs." << totalAmount << endl;
    }

    void generatePayment()
    {
        payment = new Payment(totalAmount);
    }

    void processPayment()
    {
        if (payment)
        {
            payment->processPayment();
        }
        else
        {
            cout << "Payment has not been generated.\n";
        }
    }
};

class RestaurantOrderingSystem
{
    Menu menu;

public:
    void addMenuItems()
    {
        int numItems;
        cout << "How many items do you want to add? ";
        cin >> numItems;
        menu.addItems(numItems);
    }

    void removeMenuItem()
    {
        string name;
        cout << "Enter the name of the item to remove: ";
        cin >> name;
        menu.removeItem(name);
    }

    void displayMenu() const
    {
        menu.displayMenu();
    }

    void placeOrder()
    {
        Order order;
        string itemName;
        char choice;

        cout << "\nEnter items to order (type 'done' to finish):\n";
        while (true)
        {
            cout << "Item name: ";
            cin >> itemName;
            if (itemName == "done")
                break;

            MenuItem *item = menu.getItem(itemName);
            if (item)
            {
                order.addItem(item);
            }
            else
            {
                cout << "Item not found in menu.\n";
            }
        }

        order.displayOrder();
        order.generatePayment();

        cout << "Proceed with payment? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            order.processPayment();
        }
        else
        {
            cout << "Payment canceled.\n";
        }
    }
};

int main()
{
    RestaurantOrderingSystem restaurant;
    int choice;

    while (true)
    {
        cout << "\n--- Restaurant Management System ---\n";
        cout << "1. Add Menu Items\n";
        cout << "2. Remove Menu Item\n";
        cout << "3. Display Menu\n";
        cout << "4. Place Order\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            restaurant.addMenuItems();
            break;
        case 2:
            restaurant.removeMenuItem();
            break;
        case 3:
            restaurant.displayMenu();
            break;
        case 4:
            restaurant.placeOrder();
            break;
        case 5:
            cout << "Exiting system...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}