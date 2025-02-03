#include <iostream>
#include <cstring>
using namespace std;
char* swap_string(const char* str, int n) {
int len = strlen(str);
if (n <= 0 || n > len) {
return nullptr;
}
char* newStr = new char[len + 1];
char* ptr = newStr;
const char* lastN = str + (len - n);
while (*lastN) {
*ptr++ = *lastN++;
}
const char* firstPart = str;
for (int i = 0; i < len - n; i++) {
*ptr++ = *firstPart++;
}
*ptr = '\0';
return newStr;
}
int main() {
char str[100];
int n;
cout << "Enter a string: ";
cin.getline(str, 100);
cout << "Enter the number of characters to shift: ";
cin >> n;
char* result = swap_string(str, n);
if (result) {
cout << "Shifted string after shifting last " << n << " characters: " << result << endl;
delete[ ] result;
} 
else {
cout << "Invalid shift value!" << endl;
} return 0;
}
