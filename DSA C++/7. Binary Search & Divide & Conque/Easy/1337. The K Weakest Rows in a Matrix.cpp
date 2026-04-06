// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

//     The number of soldiers in row i is less than the number of soldiers in row j.
//     Both rows have the same number of soldiers and i < j.

// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

// Example 1:

// Input: mat = 
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]], 
// k = 3
// Output: [2,0,3]
// Explanation: 
// The number of soldiers in each row is: 
// - Row 0: 2 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 2 
// - Row 4: 5 
// The rows ordered from weakest to strongest are [2,0,3,1,4].

// Example 2:

// Input: mat = 
// [[1,0,0,0],
//  [1,1,1,1],
//  [1,0,0,0],
//  [1,0,0,0]], 
// k = 2
// Output: [0,2]
// Explanation: 
// The number of soldiers in each row is: 
// - Row 0: 1 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 1 
// The rows ordered from weakest to strongest are [0,2,3,1].

 

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     2 <= n, m <= 100
//     1 <= k <= m
//     matrix[i][j] is either 0 or 1.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
      vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
          vector<pair<int,int>> v; // {soldiers, index}
  
          int m = mat.size();
          int n = mat[0].size();
  
          // Step 1: count soldiers (linear)
          for(int i = 0; i < m; i++) {
              int count = 0;
              for(int j = 0; j < n; j++) {
                  if(mat[i][j] == 1) count++;
              }
              v.push_back({count, i});
          }
  
          // Step 2: sort
          sort(v.begin(), v.end());
  
          // Step 3: take first k indices
          vector<int> ans;
          for(int i = 0; i < k; i++) {
              ans.push_back(v[i].second);
          }
  
          return ans;
      }
  };
class Solution {
public:
    int countSoldiers(vector<int>& row) {
        int low = 0, high = row.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return low; // number of 1's
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> strength; // {soldier_count, row_index}

        for (int i = 0; i < mat.size(); i++) {
            int soldiers = countSoldiers(mat[i]);
            strength.push_back({soldiers, i});
        }

        sort(strength.begin(), strength.end()); // sort by soldier count, then index

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(strength[i].second);
        }

        return result;
    }
};

// 🔹 Driver code
int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k = 3;

    Solution sol;
    vector<int> ans = sol.kWeakestRows(mat, k);

    cout << "Weakest " << k << " rows: ";
    for (int i : ans) cout << i << " ";
    cout << endl;
}
