// Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

// Examples:

// Input: mat[][] = [[1, 3, 5], 
//                 [2, 6, 9], 
//                 [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

// Input: mat[][] = [[2, 4, 9],
//                 [3, 6, 7],
//                 [4, 7, 10]]
// Output: 6
// Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.

// Input: mat = [[3], [4], [8]]
// Output: 4
// Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.

// Constraints:
// 1 ≤ n, m ≤ 400
// 1 ≤ mat[i][j] ≤ 2000


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
      // Function to find the median of a row-wise sorted matrix
      int findMedian(vector<vector<int>>& matrix) {
          
          // Create a list to store all elements
          vector<int> elements;
  
          // Traverse each row of the matrix
          for (auto& row : matrix) {
  
              // Traverse each element in the current row
              for (int val : row) {
  
                  // Add the element to the list
                  elements.push_back(val);
              }
          }
  
          // Sort the collected elements
          sort(elements.begin(), elements.end());
  
          // Return the middle element (median)
          int n = elements.size();
          return elements[n / 2];
      }
  };

  

  
class Solution {
  public:
   int countLessEqual(vector<int>& row, int mid) {
        // Using upper_bound to find count efficiently
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    int median(vector<vector<int>> &matrix) {
        // code here
         // Number of rows and columns
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Minimum possible element in matrix
        int low = matrix[0][0];

        // Maximum possible element in matrix
        int high = matrix[0][cols - 1];
        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        // Binary search over the value range
        while (low < high) {
            int mid = (low + high) / 2;

            // Count elements ≤ mid
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countLessEqual(matrix[i], mid);
            }

            // If count is less than half, median is greater
            if (count < (rows * cols + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }

        // Final low is the median
        return low;
    }
};