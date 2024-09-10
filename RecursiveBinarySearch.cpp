#include<iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key)
            return mid;
        
        if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, right, key);
        
        return binarySearchRecursive(arr, left, mid - 1, key);
    }
    return -1; // Key not found
}
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = binarySearchRecursive(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;
    return 0;
}

