#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n-1] > arr[n-2]) return n-1;
        
        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            } else if (arr[mid] > arr[mid-1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Should never reach here for a valid mountain array
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> arr1 = {0, 2, 1, 0};
    vector<int> arr2 = {0, 10, 5, 2};
    vector<int> arr3 = {3, 4, 5, 1};

    cout << sol.peakIndexInMountainArray(arr1) << endl; // Output: 1
    cout << sol.peakIndexInMountainArray(arr2) << endl; // Output: 1
    cout << sol.peakIndexInMountainArray(arr3) << endl; // Output: 2

    return 0;
}
