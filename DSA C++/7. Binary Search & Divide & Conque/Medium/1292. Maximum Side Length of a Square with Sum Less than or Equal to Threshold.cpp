#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // Step 1: Build prefix sum matrix
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1] 
                             + prefix[i - 1][j] 
                             + prefix[i][j - 1] 
                             - prefix[i - 1][j - 1];
            }
        }

        // Step 2: Binary search on side length
        int low = 0, high = min(m, n), ans = 0;

        auto isValid = [&](int k) -> bool {
            for (int i = k; i <= m; i++) {
                for (int j = k; j <= n; j++) {
                    int total = prefix[i][j] - prefix[i - k][j] - prefix[i][j - k] + prefix[i - k][j - k];
                    if (total <= threshold) return true;
                }
            }
            return false;
        };

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(mid)) {
                ans = mid;   // try larger square
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2}
    };
    int threshold = 4;

    Solution sol;
    cout << sol.maxSideLength(mat, threshold) << endl; // Output: 2
}
