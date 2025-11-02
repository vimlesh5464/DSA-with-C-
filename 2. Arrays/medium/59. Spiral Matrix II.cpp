#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      vector<vector<int>> generateMatrix(int n) {
          vector<vector<int>> matrix(n, vector<int>(n, 0)); // initialize n x n with 0
  
          int srow = 0, erow = n - 1;   // starting & ending row
          int scol = 0, ecol = n - 1;   // starting & ending column
          int num = 1;                  // number to fill (1 to n*n)
  
          while (srow <= erow && scol <= ecol) {
              // Traverse Top Row (→)
              for (int j = scol; j <= ecol; j++)
                  matrix[srow][j] = num++;
  
              // Traverse Right Column (↓)
              for (int i = srow + 1; i <= erow; i++)
                  matrix[i][ecol] = num++;
  
              // Traverse Bottom Row (←)
              if (srow < erow) {
                  for (int j = ecol - 1; j >= scol; j--)
                      matrix[erow][j] = num++;
              }
  
              // Traverse Left Column (↑)
              if (scol < ecol) {
                  for (int i = erow - 1; i > srow; i--)
                      matrix[i][scol] = num++;
              }
  
              // Move inward for next layer
              srow++;
              erow--;
              scol++;
              ecol--;
          }
  
          return matrix;
      }
  };