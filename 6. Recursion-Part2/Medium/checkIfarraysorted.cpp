#include<iostream>
using namespace std;
//check array is sorted or not
bool sortedArray(int arr[], int n, int i = 0) {
    if (i == n - 1) {
        return true;  // Reached end, array is sorted
    }
    if (arr[i] > arr[i + 1]) {
        return false;  // Not sorted
    }
    return sortedArray(arr, n, i + 1);  // Check next pair
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (sortedArray(arr, n))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is NOT sorted" << endl;

    return 0;
}
