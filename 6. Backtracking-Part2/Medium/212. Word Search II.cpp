// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:

// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]

// Example 2:

// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []

 

// Constraints:

//     m == board.length
//     n == board[i].length
//     1 <= m, n <= 12
//     board[i][j] is a lowercase English letter.
//     1 <= words.length <= 3 * 104
//     1 <= words[i].length <= 10
//     words[i] consists of lowercase English letters.
//     All the strings of words are unique.

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
  