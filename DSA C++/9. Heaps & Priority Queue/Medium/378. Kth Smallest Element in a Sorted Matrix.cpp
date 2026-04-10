// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

 

// Example 1:

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

// Example 2:

// Input: matrix = [[-5]], k = 1
// Output: -5

 

// Constraints:

//     n == matrix.length == matrix[i].length
//     1 <= n <= 300
//     -109 <= matrix[i][j] <= 109
//     All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
//     1 <= k <= n2

 

// Follow up:

//     Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
//     Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.


#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      int kthSmallest(vector<vector<int>>& matrix, int k) {
          vector<int> temp;
  
          int n = matrix.size();
          int m = matrix[0].size();
  
          // Linear search: push all elements into vector
          for(int i = 0; i < n; i++) {
              for(int j = 0; j < m; j++) {
                  temp.push_back(matrix[i][j]);
              }
          }
  
          // Sort all values
          sort(temp.begin(), temp.end());
  
          // k-th smallest (1-based)
          return temp[k - 1];
      }
  };


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Min heap: {value, row, col}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > minHeap;

        // Step 1: Push first element of each row
        for (int i = 0; i < n; i++) {
            minHeap.push({matrix[i][0], i, 0});
        }

        // Step 2: Extract k times
        while (--k) {
            auto [val, r, c] = minHeap.top();
            minHeap.pop();

            // Push next element in same row
            if (c + 1 < n) {
                minHeap.push({matrix[r][c+1], r, c+1});
            }
        }

        return get<0>(minHeap.top());
    }
};