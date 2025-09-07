
#include <iostream>
#include<vector>
using namespace std;
// Approach 1: Brute Force
// Traverse every element of the matrix and check if it equals the target.
// Time Complexity: O(m*n)
// Space Complexity: O(1)

class Solution {
  public:
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size();
          int m = matrix[0].size();
  
          for(int i = 0; i < n; i++) {
              for(int j = 0; j < m; j++) {
                  if(matrix[i][j] == target) return true;
              }
          }
          return false;
      }
  };
  // Approach 2: Binary Search (Row-wise)
  // For each row, do binary search since the row is sorted. 
  // This reduces the search in each row to O(log m).
  // Time Complexity: O(n log m)
  // Space Complexity: O(1)
  class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
    
            for(int i = 0; i < n; i++) {
                int left = 0, right = m - 1;
    
                // Binary search in current row
                while(left <= right) {
                    int mid = left + (right - left) / 2;
    
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] < target) left = mid + 1;
                    else right = mid - 1;
                }
            }
    
            return false; // target not found in any row
        }
    };
  
//   Approach 3: Optimal Approach – Search from Top Right Corner Idea:
//   Start at top-right corner (0, m-1).
//   Compare the element with target:
//   If equal → return true
//   If element > target → move left (decrease column) 
//   If element < target → move down (increase row)
//  Repeat until you go out of bounds.
//   Why it works:
//   Each step eliminates either a row or a column, because rows and columns are sorted.  
// Time	O(n + m) → at most n moves down and m moves left
// Space	O(1) → constant extra space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1; // start from top-right

        while(row < n && col >= 0) {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;  // move left
            else row++;                                 // move down
        }

        return false; // not found
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 5;

    if(s.searchMatrix(matrix, target))
        cout << "Target found!" << endl;
    else
        cout << "Target not found!" << endl;

    return 0;
}
