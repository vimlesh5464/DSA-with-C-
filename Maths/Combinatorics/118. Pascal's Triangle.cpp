// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:

// Input: numRows = 1
// Output: [[1]]

 

// Constraints:

//     1 <= numRows <= 30

#include <iostream>
using namespace std;
class Solution {
  public:
      vector<vector<int>> generate(int numRows) {
           // Result vector to hold all rows
          vector<vector<int>> triangle;
  
          // Loop for each row
          for (int i = 0; i < numRows; i++) {
              // Create a row with size (i+1) and initialize all elements to 1
              vector<int> row(i + 1, 1);
  
              // Fill elements from index 1 to i-1 (middle values)
              for (int j = 1; j < i; j++) {
                  // Each element = sum of two elements above it
                  row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
              }
  
              // Add current row to the triangle
              triangle.push_back(row);
          }
          return triangle;
      }
  };