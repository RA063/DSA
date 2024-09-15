#include<iostream>
using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;
int main() {
    int arr[MAX_ROWS][MAX_COLS];
    int rows, cols;
    cout << "Enter the number of rows and  columns: ";
    cin >> rows >> cols;
    cout << "Enter the elements of the 2D array:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        } }
    int row_pos, col_pos, element;
    cout << "Enter the row and column  position to insert the element: ";
    cin >> row_pos >> col_pos;
    cout << "Enter the element to be inserted: ";
    cin >> element;
    if(row_pos < 0 || row_pos >= rows || col_pos < 0 || col_pos >= cols) {
        cout << "Invalid position!";
        return 1;}			 // Shift the elements to make space for the new element
    for(int i = rows - 1; i >= row_pos; i--) {
        for(int j = cols - 1; j >= col_pos; j--) {
            arr[i][j] = arr[i - 1][j];
        }	}		// Insert the element at the specified position
    arr[row_pos][col_pos] = element;
    rows++;		// Increment the number of rows and columns
    cols++;
    cout << "Updated 2D array:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";}
        cout << endl;
    }
     return 0;
}

