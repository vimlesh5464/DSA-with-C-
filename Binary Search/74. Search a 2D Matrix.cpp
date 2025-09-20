#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;

        int n = matrix[0].size();
        if (n == 0) return false;

        // Brute force search
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;
    cout << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;

    target = 13;
    cout << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}
