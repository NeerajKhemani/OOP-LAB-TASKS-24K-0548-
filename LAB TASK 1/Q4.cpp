#include <iostream>
using namespace std;
int maxArea(int height[], int n) {
int left = 0, right = n - 1, max_area = 0;
while (left < right) {
int width = right - left;
int min_height = (height[left] < height[right]) ? height[left] :
height[right];
int current_area = min_height * width;
if (current_area > max_area) max_area = current_area;
if (height[left] < height[right]) left++;
else right--;
}
return max_area;
}
int main() {
int n;
cout << "Enter the number of vertical lines: ";
cin >> n;
int height[n];
cout << "Enter the heights of the lines: ";
for (int i = 0; i < n; i++) {
cin >> height[i];
}
cout << "Maximum area: " << maxArea(height, n) << endl;
return 0;
}
