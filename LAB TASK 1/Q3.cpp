#include <iostream>
using namespace std;
int Sum(int nums[], int size, int target, int result[2]) {
for (int i = 0; i < size; i++) {
for (int j = i + 1; j < size; j++) {
if (nums[i] + nums[j] == target) {
result[0] = i;
result[1] = j;
return 1;
}
}
}
return 0;
}
int main() {
int size, target;
cout << "Enter the number of elements: ";
cin >> size;
if (size < 2) {
cout << "At least two numbers are required." << endl;
return 1;
}
int nums[size];
cout << "Enter the numbers: ";
for (int i = 0; i < size; i++) {
cin >> nums[i];
}
cout << "Enter the target sum: ";
cin >> target;
int result[2];
if (Sum(nums, size, target, result)) {
cout << "Indices: " << result[0] << " " << result[1] << endl;
} else {
cout << "No pair found." << endl;
}
return 0;
}