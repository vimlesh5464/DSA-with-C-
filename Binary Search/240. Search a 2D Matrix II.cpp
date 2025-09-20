#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1; // start from top-right

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } 
            else if (matrix[row][col] > target) {
                col--; // move left
            } 
            else {
                row++; // move down
            }
        }
        return false; // not found
    }
};

// Driver code for testing
int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 5;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Found " << target << endl;
    } else {
        cout << "Not Found " << target << endl;
    }

    return 0;
}
