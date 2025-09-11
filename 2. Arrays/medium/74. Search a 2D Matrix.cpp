#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//Aproaches
//1. Brute Force
// Time Complexity: O(m*n)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &row : matrix) {
            for(int num : row) {
                if(num == target) return true;
            }
        }
        return false;
    }
};

//2. Binary Search (Optimal) ✅
// Time Complexity: O(log(m*n))
// Space Complexity: O(1)

class Solution {
  public:
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int m = matrix.size();
          int n = matrix[0].size();
          int left = 0, right = m*n - 1;
  
          while(left <= right) {
              int mid = left + (right - left)/2;
              int midVal = matrix[mid/n][mid%n];
  
              if(midVal == target) return true;
              else if(midVal < target) left = mid + 1;
              else right = mid - 1;
          }
          return false;
      }
  };
int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << (s.searchMatrix(matrix, target) ? "true" : "false") << endl;
    return 0;
}
