#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * @brief Finds the k elements in a sorted array that are closest to x.
 * * Uses binary search to find the optimal starting index (low) of the k-sized window.
 * * @param arr The sorted input vector of integers.
 * @param k The number of elements to return.
 * @param x The target value.
 * @return A vector containing the k closest elements.
 */
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // The search space is for the starting index (low) of the k-sized window.
    // The smallest possible start index is 0.
    int low = 0; 
    // The largest possible start index is arr.size() - k, 
    // which makes the window end at arr.size() - 1.
    int high = arr.size() - k; 
    
    // Binary search to find the best 'low'
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // Comparison: Compare the distance of the element *just outside the left* // of the current window (arr[mid]) with the element *just outside the right* // of the current window (arr[mid + k]).
        
        // We compare: |x - arr[mid]| vs. |arr[mid + k] - x|
        // Since arr is sorted, we can use the simplified form:
        // x - arr[mid] is the distance to the left element.
        // arr[mid + k] - x is the distance to the right element.
        
        if (x - arr[mid] > arr[mid + k] - x) {
            // The left element (arr[mid]) is farther from x.
            // We should discard it and shift the window to the right.
            low = mid + 1;
        } else {
            // The left element (arr[mid]) is closer or equally close (in which 
            // case we prefer the smaller value, arr[mid], according to problem rules).
            // We keep mid as a potential answer and try to find a better one on the left.
            high = mid;
        }
    }
    
    // When the loop ends, 'low' is the optimal starting index.
    // Return the subarray from arr.begin() + low up to arr.begin() + low + k.
    return vector<int>(arr.begin() + low, arr.begin() + low + k);
}

// Main function for user input and output
int main() {
    int n, k, x;

    cout << "Enter the size of the array (N): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid array size." << endl;
        return 1;
    }

    cout << "Enter the number of closest elements to find (K): ";
    if (!(cin >> k) || k <= 0 || k > n) {
        cerr << "Invalid K value. K must be > 0 and <= N." << endl;
        return 1;
    }

    cout << "Enter the target value (X): ";
    if (!(cin >> x)) {
        cerr << "Invalid target value X." << endl;
        return 1;
    }

    cout << "Enter the " << n << " **sorted** elements (e.g., 1 2 3 4 5):" << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            cerr << "Invalid element input." << endl;
            return 1;
        }
    }
    
    // --- Function Call ---
    vector<int> result = findClosestElements(arr, k, x);

    // --- Output Result ---
    cout << "\nInput Array: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    cout << "K = " << k << ", X = " << x << endl;
    
    cout << "The " << k << " closest elements are: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}