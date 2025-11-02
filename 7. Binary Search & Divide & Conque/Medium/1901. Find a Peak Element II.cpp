#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int midCol = low + (high - low) / 2;

            // 🔹 Find max element in the mid column
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int left = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int right = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

            // 🔹 Check if current is peak
            if (mat[maxRow][midCol] > left && mat[maxRow][midCol] > right) {
                return {maxRow, midCol};
            }

            // 🔹 Move to the direction of larger neighbor
            if (left > mat[maxRow][midCol])
                high = midCol - 1;
            else
                low = midCol + 1;
        }

        return {-1, -1}; // Should never reach here
    }
};

// 🔹 Driver code
int main() {
    vector<vector<int>> mat = {
        {1, 4, 3, 2},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Solution sol;
    vector<int> ans = sol.findPeakGrid(mat);
    cout << "Peak at: (" << ans[0] << ", " << ans[1] << ")\n";
    return 0;
}
