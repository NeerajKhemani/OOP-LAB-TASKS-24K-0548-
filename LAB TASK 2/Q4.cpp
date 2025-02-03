#include <iostream>
using namespace std;
int* unique(int* arr, int size, int& newSize) {
if (size == 0) {
newSize = 0;
return nullptr;
}
int* temp = new int[size];
newSize = 0;
for (int i = 0; i < size; i++) {
bool isDuplicate = false;
for (int j = 0; j < newSize; j++) {
if (arr[i] == temp[j]) {
isDuplicate = true;
break;
}
}
if (!isDuplicate) {
temp[newSize++] = arr[i];
}
}
int* result = new int[newSize];
for (int i = 0; i < newSize; i++) {
result[i] = temp[i];
}
delete[ ] temp;
return result;
}
int main() {
int size;
cout << "Enter the size of the array: " ;
cin >> size;
if (size <= 0) {
cout << "Invalid size!" << endl;
return 1;
}
int* arr = new int[size];
cout << "Enter the elements of the array: " << endl;;
for (int i = 0; i < size; i++) {
cin >> arr[i];
}
int newSize;
int* uniqueArr = unique(arr, size, newSize);
cout << "Array with unique values: ";
for (int i = 0; i < newSize; i++) {
cout << uniqueArr[i] << " ";
}
cout << endl;
delete[ ] arr;
delete[ ] uniqueArr;
return 0;
}
