// You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

// Note:

//     The array follows 0-based indexing.
//     The number of rows and columns in the array are denoted by n and m respectively.

// Examples:

// Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
// Output: 2
// Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

// Input: arr[][] = [[0,0], [1,1]]
// Output: 1
// Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.

// Input: arr[][] = [[0,0], [0,0]]
// Output: -1
// Explanation: No row contains any 1s, so the output is -1.

// Constraints:
// 1 ≤ arr.size(), arr[i].size() ≤ 103
// 0 ≤ arr[i][j] ≤ 1 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rowWithMax1s(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    int maxRow = -1;
    int maxOnes = 0;

    // Traverse each row
    for (int i = 0; i < n; i++) {

        int countOnes = 0;

        // Count 1s in current row
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                countOnes++;
            }
        }

        // Update answer if better row found
        if (countOnes > maxOnes) {
            maxOnes = countOnes;
            maxRow = i;
        }
    }

    // If no 1 found in any row
    if (maxOnes == 0) return -1;

    return maxRow;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << rowWithMax1s(arr) << endl;

    return 0;
}
// User function template for C++
class Solution {
  public:
   int lowerBound(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;  // Default if x not found

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;       // Possible answer
                high = mid - 1;  // Look for smaller index
            } else {
                low = mid + 1;   // Search right half
            }
        }
        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt_max = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cnt_ones = m - lowerBound(matrix[i], m, 1);  // 1s = total - index of first 1
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};