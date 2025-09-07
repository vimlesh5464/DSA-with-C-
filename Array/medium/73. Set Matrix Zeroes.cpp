
#include <iostream>
#include<vector>
using namespace std;
// Complexity Analysis
// Aspect	Complexity
// Time	O(n*m) → traverse the matrix twice
// Space	O(n + m) → for row and col arrays
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();

        // Vectors to mark rows and columns to be zeroed
        vector<int> row(n, 0), col(m, 0);

        // First pass: mark the rows and columns that contain 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: set cells to 0 based on row/col markers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
//Aproaches2
// Complexity Analysis
// Aspect	Complexity
// Time	O(n * m) → traverse matrix multiple times
// Space	O(1) → no extra space used except a few boolean variables
class Solution {
  public:
      void setZeroes(vector<vector<int>>& matrix) {
          int n = matrix.size();
          int m = matrix[0].size();
          bool firstRowZero = false, firstColZero = false;
  
          // Step 1: Check if first row has any zero
          for(int j = 0; j < m; j++) {
              if(matrix[0][j] == 0) firstRowZero = true;
          }
  
          // Step 2: Check if first column has any zero
          for(int i = 0; i < n; i++) {
              if(matrix[i][0] == 0) firstColZero = true;
          }
  
          // Step 3: Use first row and first column as markers
          for(int i = 1; i < n; i++) {
              for(int j = 1; j < m; j++) {
                  if(matrix[i][j] == 0) {
                      matrix[i][0] = 0;
                      matrix[0][j] = 0;
                  }
              }
          }
  
          // Step 4: Set zeroes based on markers
          for(int i = 1; i < n; i++) {
              for(int j = 1; j < m; j++) {
                  if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                      matrix[i][j] = 0;
                  }
              }
          }
  
          // Step 5: Update first row if needed
          if(firstRowZero) {
              for(int j = 0; j < m; j++) matrix[0][j] = 0;
          }
  
          // Step 6: Update first column if needed
          if(firstColZero) {
              for(int i = 0; i < n; i++) matrix[i][0] = 0;
          }
      }
  };
  
  

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    s.setZeroes(matrix);

    cout << "Matrix after setting zeroes:" << endl;
    for (auto &row : matrix) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
