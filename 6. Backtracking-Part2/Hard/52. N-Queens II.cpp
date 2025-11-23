#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
  public:
      bool isSafe(vector<string>& board, int row, int col, int n) {
          // Check left side of current row
          for (int j = 0; j < col; j++) {
              if (board[row][j] == 'Q') return false;
          }
  
          // Check upper-left diagonal
          for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
              if (board[i][j] == 'Q') return false;
          }
  
          // Check lower-left diagonal
          for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
              if (board[i][j] == 'Q') return false;
          }
  
          return true;
      }
  
      void solve(int n, int col, vector<string>& board, int& count) {
          // Base case: all queens are placed
          if (col == n) {
              count++;
              return;
          }
  
          for (int row = 0; row < n; row++) {
              if (isSafe(board, row, col, n)) {
                  board[row][col] = 'Q';        // Place the queen
                  solve(n, col + 1, board, count); // Recurse
                  board[row][col] = '.';        // Backtrack
              }
          }
      }
  
      int totalNQueens(int n) {
          vector<string> board(n, string(n, '.'));
          int count = 0;
          solve(n, 0, board, count);
          return count;
      }
  };
  