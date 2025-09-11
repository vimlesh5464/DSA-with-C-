#include <iostream>
#include<vector>
using namespace std;
// Approach (Layer by Layer Traversal)
// Maintain boundaries:
// srow = starting row
// erow = ending row
// scol = starting column
// ecol = ending column
// Traverse top row → right column → bottom row → left column for the current layer.
// Move the boundaries inward (srow++, erow--, scol++, ecol--) for the next inner layer.
// Continue until srow > erow or scol > ecol.
// Time	O(n * m) → each element is visited once
// Space	O(1) extra space → excluding output vector

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();

        int srow = 0, erow = n - 1;
        int scol = 0, ecol = m - 1;

        while (srow <= erow && scol <= ecol) {
            // Top row
            for (int j = scol; j <= ecol; j++)
                result.push_back(matrix[srow][j]);

            // Right column
            for (int i = srow + 1; i <= erow; i++)
                result.push_back(matrix[i][ecol]);

            // Bottom row
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--)
                    result.push_back(matrix[erow][j]);
            }

            // Left column
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--)
                    result.push_back(matrix[i][scol]);
            }

            srow++; erow--; scol++; ecol--; // Move to inner layer
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = s.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for(int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
