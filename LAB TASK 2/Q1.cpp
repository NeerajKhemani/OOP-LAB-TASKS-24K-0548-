#include <iostream>
using namespace std;
int main() {
int n;
float sum = 0.0;
cout << "Enter the number of elements in the array: ";
cin >> n;
float* ptr = new float[n];
cout << "Enter the elements of the array: ";
for (int i = 0; i < n; i++) {
cin >> *(ptr +i);
sum += *(ptr +i);
}
float avg = sum / n;
float low_diff = avg - *(ptr + 0);
if(low_diff < 0){
low_diff = -low_diff;
}
float diff;
int index = 0;
for (int i = 1; i < n; i++) {
diff = avg - *(ptr + i);
if (diff < 0){
diff = -diff;
}
if (diff < low_diff) {
low_diff = diff;
index = i; }
}
cout << "The average of the array is: " << avg << endl;
cout << "The closest number to average in array is: " << ptr[index];
delete[] ptr;
return 0;
}
