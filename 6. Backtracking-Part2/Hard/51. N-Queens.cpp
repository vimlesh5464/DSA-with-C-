#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
  public:
  // Function to check if it's safe to place a Queen at board[row][col]
  bool isSafe(vector<string>& board, int row, int col, int n) {
      // Check left side of the current row (horizontal)
      for (int j = 0; j < col; j++) {
          if (board[row][j] == 'Q')
              return false;
      }
  
      // Check upper-left diagonal
      for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
          if (board[i][j] == 'Q')
              return false;
      }
  
      // Check lower-left diagonal
      for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
          if (board[i][j] == 'Q')
              return false;
      }
  
      // Check same column (optional if we place one queen per column)
      for (int i = 0; i < row; i++) {
          if (board[i][col] == 'Q')
              return false;
      }
  
      return true;
  }
  
  // Recursive function to solve N-Queens
  void solve(int n, int col, vector<string>& board, vector<vector<string>>& ans) {
      // Base case: all queens are placed
      if (col == n) {
          ans.push_back(board);
          return;
      }
  
      // Try placing a queen in each row of the current column
      for (int row = 0; row < n; row++) {
          if (isSafe(board, row, col, n)) {
              board[row][col] = 'Q';      // place the queen
              solve(n,col + 1, board, ans);  // recurse for next column
              board[row][col] = '.';      // backtrack
          }
      }
  }
      vector<vector<string>> solveNQueens(int n) {
          vector<vector<string>>ans;
          vector<string> board(n, string(n,'.'));
          solve(n,0,board,ans);
          return ans;
      }
  };