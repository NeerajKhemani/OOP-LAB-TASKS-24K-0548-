#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int** allocateMatrix(int rows, int cols) {
int** matrix = new int*[rows];
for (int i = 0; i < rows; i++) {
matrix[i] = new int[cols];
}
return matrix;
}
void fillMatrix(int** matrix, int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
matrix[i][j] = rand() % 100 + 1;
}
}
}
void printMatrix(int** matrix, int rows, int cols) {
for (int i = 0; i < rows; i++) {
cout << "[ ";
for (int j = 0; j < cols; j++) {
    cout << matrix[i][j] << (j < cols - 1 ? " " : "");
}
cout << " ]" << endl;
}
}
int calculateSum(int** matrix, int rows, int cols) {
int sum = 0;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
sum += matrix[i][j];
}
}
return sum;
}
void rowColumnSums(int** matrix, int rows, int cols, int*
rowSums, int* colSums) {
for (int i = 0; i < rows; i++) rowSums[i] = 0;
for (int j = 0; j < cols; j++) colSums[j] = 0;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
rowSums[i] += matrix[i][j];
colSums[j] += matrix[i][j];
}
}
cout << "Row sums: ";
for (int i = 0; i < rows; i++) {
cout << rowSums[i] << (i < rows - 1 ? ", " : "");
}
cout << endl;
cout << "Column sums: ";
for (int j = 0; j < cols; j++) {
cout << colSums[j] << (j < cols - 1 ? ", " : "");
}
cout << endl;
}
void findMaxRowCol(int* rowSums, int* colSums, int rows, int
cols) {
int maxRowSum = rowSums[0], maxRowIndex = 0;
int maxColSum = colSums[0], maxColIndex = 0;
for (int i = 1; i < rows; i++) {
if (rowSums[i] > maxRowSum) {
maxRowSum = rowSums[i];
maxRowIndex = i;
}
}
for (int j = 1; j < cols; j++) {
if (colSums[j] > maxColSum) {
maxColSum = colSums[j];
maxColIndex = j;
}
}
cout << "Row with highest sum: Row " << maxRowIndex + 1 <<
endl;
cout << "Column with highest sum: Column " << maxColIndex + 1
<< endl;
}
int** transposeMatrix(int** matrix, int rows, int cols) {
int** transposed = allocateMatrix(cols, rows);
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
transposed[j][i] = matrix[i][j];
}
}
return transposed;
}
void freeMatrix(int** matrix, int rows) {
for (int i = 0; i < rows; i++) {
delete[ ] matrix[i];
}
delete[ ] matrix;
}
int main() {
srand(time(0));
int rows, cols;
cout << "Enter number of rows: ";
cin >> rows;
cout << "Enter number of columns: ";
cin >> cols;
if (rows <= 0 || cols <= 0) {
cout << "Invalid matrix size!" << endl;
return 1;
}
int** matrix = allocateMatrix(rows, cols);
fillMatrix(matrix, rows, cols);
cout << "\nOriginal Matrix:\n";
printMatrix(matrix, rows, cols);
int totalSum = calculateSum(matrix, rows, cols);
cout << "Sum of all elements: " << totalSum << endl;
int* rowSums = new int[rows];
int* colSums = new int[cols];
rowColumnSums(matrix, rows, cols, rowSums, colSums);
findMaxRowCol(rowSums, colSums, rows, cols);
int** transposed = transposeMatrix(matrix, rows, cols);
cout << "\nTransposed Matrix:\n";
printMatrix(transposed, cols, rows);
freeMatrix(matrix, rows);
freeMatrix(transposed, cols);
delete[ ] rowSums;
delete[ ] colSums;
return 0;
}
