#include <iostream>
#include <cstring>
using namespace std;
int countVowels(const char* str) {
int vowelCount = 0;
char vowels[] = "aeiouAEIOU";
while (*str != '\0') {
if (strchr(vowels, *str)) {
vowelCount++;
}
str++;
}
return vowelCount;
}
int main() {
int n;
cout << "Enter the number of strings: ";
cin >> n;
char** strings = new char*[n];
cin.ignore();
for (int i = 0; i < n; i++) {
cout << "Enter string " << i + 1 << ": ";
strings[i] = new char[100];
cin.getline(strings[i], 100);
}
cout << "\nStrings in reverse order:\n";
for (char** ptr = strings + n - 1; ptr >= strings; ptr--) {
cout << *ptr << endl;
}
int maxVowels = 0;
char* stringWithMostVowels = NULL;
for (char** ptr = strings; ptr < strings + n; ptr++) {
int vowelCount = countVowels(*ptr);
if (vowelCount > maxVowels) {
maxVowels = vowelCount;
stringWithMostVowels = *ptr;
}
}
cout << "\nString with the most vowels: " << stringWithMostVowels
<< endl;
int totalLength = 0;
for (char** ptr = strings; ptr < strings + n; ptr++) {
totalLength += strlen(*ptr);
}
double averageLength = static_cast<double>(totalLength) / n;
cout << "Average length of the strings: " << averageLength << endl;
for (int i = 0; i < n; i++) {
delete[] strings[i];
}
delete[] strings;
return 0;
}
