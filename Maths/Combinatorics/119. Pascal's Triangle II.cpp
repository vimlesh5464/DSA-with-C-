// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]

// Example 2:

// Input: rowIndex = 0
// Output: [1]

// Example 3:

// Input: rowIndex = 1
// Output: [1,1]

 

// Constraints:

//     0 <= rowIndex <= 33

 

// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

#include <iostream>
using namespace std;
class Solution {
  public:
      vector<int> getRow(int n) {
          vector<vector<int>> triangle;
  
      for (int i = 0; i <= n; i++) {
  
          vector<int> row(i + 1, 1);
  
          for (int j = 1; j < i; j++) {
              row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
          }
  
          triangle.push_back(row);
      }
  
  return triangle[n];
      }
  };