#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      
      bool dfs(vector<vector<char>>& board, string &word, int i, int j, int index) {
          if (index == word.size()) return true;
  
          if (i < 0 || i >= board.size() ||
              j < 0 || j >= board[0].size() ||
              board[i][j] != word[index])
              return false;
  
          char temp = board[i][j];
          board[i][j] = '#';  // mark visited
  
          bool found =
              dfs(board, word, i + 1, j, index + 1) ||
              dfs(board, word, i - 1, j, index + 1) ||
              dfs(board, word, i, j + 1, index + 1) ||
              dfs(board, word, i, j - 1, index + 1);
  
          board[i][j] = temp;  // backtrack
          return found;
      }
  
      vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
          vector<string> ans;
  
          for (string &word : words) {
              bool added = false;
              for (int i = 0; i < board.size() && !added; i++) {
                  for (int j = 0; j < board[0].size() && !added; j++) {
                      if (dfs(board, word, i, j, 0)) {
                          ans.push_back(word);
                          added = true;
                      }
                  }
              }
          }
  
          return ans;
      }
  };
  