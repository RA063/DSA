#include<iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the 2D array: ";
    cin >> rows >> cols;

    int arr[rows][cols];

    cout << "Enter elements of the 2D array in column-major order:\n";

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> arr[i][j];
        }
    }

    cout << "\n2D Array elements stored in column-major order:\n";

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

