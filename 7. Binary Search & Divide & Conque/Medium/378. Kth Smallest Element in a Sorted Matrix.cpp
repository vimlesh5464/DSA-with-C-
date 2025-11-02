#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            int j = n - 1;

            // Count elements <= mid
            for (int i = 0; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }

            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    Solution sol;
    cout << sol.kthSmallest(matrix, k) << endl; // Output: 13
}
