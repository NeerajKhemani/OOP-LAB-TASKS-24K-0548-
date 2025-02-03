#include <iostream>
#include <cstring>
using namespace std;
struct Product {
int id;
char name[50];
double price;
int quantity;
char category[30];
};
Product* inventory = nullptr;
int productCounter = 1;
int productCount = 0;
void addProduct(const char* name, double price, int quantity,
const char* category);
void displayProduct(int id);
void updateProduct(int id, double newPrice, int newQuantity);
void removeProduct(int id);
void listAllProducts();
void resizeInventory(int newSize);
void addProduct(const char* name, double price, int quantity,
const char* category) {
resizeInventory(productCount + 1);
Product& newProduct = inventory[productCount++];
newProduct.id = productCounter++;
strcpy(newProduct.name, name);
newProduct.price = price;
newProduct.quantity = quantity;
strcpy(newProduct.category, category);
cout << "Product added successfully! ID: " << newProduct.id <<
endl;
}
void displayProduct(int id) {
for (int i = 0; i < productCount; i++) {
if (inventory[i].id == id) {
cout << "\nProduct ID: " << inventory[i].id << endl;
cout << "Name: " << inventory[i].name << endl;
cout << "Price: Rs " << inventory[i].price << endl;
cout << "Quantity: " << inventory[i].quantity << endl;
cout << "Category: " << inventory[i].category << endl;
return;
}
}
cout << "Product not found!\n";
}
void updateProduct(int id, double newPrice, int newQuantity) {
for (int i = 0; i < productCount; i++) {
if (inventory[i].id == id) {
inventory[i].price = newPrice;
inventory[i].quantity = newQuantity;
cout << "Product updated successfully!\n";
return;
}
}
cout << "Product not found!\n";
}
void removeProduct(int id) {
int index = -1;
for (int i = 0; i < productCount; i++) {
if (inventory[i].id == id) {
index = i;
break;
}
}
if (index == -1) {
cout << "Product not found!\n";
return;
}
for (int i = index; i < productCount - 1; i++) {
inventory[i] = inventory[i + 1];
}
productCount--;
resizeInventory(productCount);
cout << "Product removed successfully!\n";
}
void listAllProducts() {
if (productCount == 0) {
cout << "No products available!\n";
return;
}
cout << "\nProduct Inventory:\n";
for (int i = 0; i < productCount; i++) {
cout << "ID: " << inventory[i].id << endl;
cout << "Name: " << inventory[i].name << endl;
cout << "Price: Rs " << inventory[i].price << endl;
cout << "Quantity: " << inventory[i].quantity << endl;
cout << "Category: " << inventory[i].category << endl;
}
}
void resizeInventory(int newSize) {
Product* newInventory = new Product[newSize];
for (int i = 0; i < productCount; i++) {
newInventory[i] = inventory[i];
}
delete[ ] inventory;
inventory = newInventory;
}
int main() {
int choice, id, quantity;
double price;
char name[50], category[30];
while (true) {
cout << "\nProduct Management System\n";
cout << "1. Add Product\n";
cout << "2. Display Product\n";
cout << "3. Update Product\n";
cout << "4. Remove Product\n";
cout << "5. List All Products\n";
cout << "6. Exit\n";
cout << "Enter choice: ";
cin >> choice;
cin.ignore();
switch (choice) {
case 1:
cout << "Enter product name: ";
cin.getline(name, 50);
cout << "Enter price: ";
cin >> price;
cout << "Enter quantity: ";
cin >> quantity;
cin.ignore();
cout << "Enter category: ";
cin.getline(category, 30);
addProduct(name, price, quantity, category);
break;
case 2:
cout << "Enter product ID: ";
cin >> id;
displayProduct(id);
break;
case 3:
cout << "Enter product ID: ";
cin >> id;
cout << "Enter new price: ";
cin >> price;
cout << "Enter new quantity: ";
cin >> quantity;
updateProduct(id, price, quantity);
break;
case 4:
cout << "Enter product ID: ";
cin >> id;
removeProduct(id);
break;
case 5:
listAllProducts();
break;
case 6:
cout << "Exiting...\n";
delete[ ] inventory;
return 0;
default:
cout << "Invalid choice! Try again.\n";
}
}
}