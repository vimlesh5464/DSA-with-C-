#include <iostream>
#include <vector>
using namespace std;


class Solution {
  public:
      vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
          int m = mat.size();
          int n = mat[0].size();
          vector<int> res(m * n);
  
          int row = 0, col = 0;
          for (int i = 0; i < m * n; i++) {
              res[i] = mat[row][col];
  
              // if the sum of indices is even -> moving up-right
              if ((row + col) % 2 == 0) {
                  if (col == n - 1) row++;        // last column → go down
                  else if (row == 0) col++;       // first row → go right
                  else { row--; col++; }          // otherwise up-right
              }
              // if the sum is odd -> moving down-left
              else {
                  if (row == m - 1) col++;        // last row → go right
                  else if (col == 0) row++;       // first col → go down
                  else { row++; col--; }          // otherwise down-left
              }
          }
          return res;
      }
  };
  