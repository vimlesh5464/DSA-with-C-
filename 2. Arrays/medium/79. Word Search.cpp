#include <iostream>
#include<vector>
using namespace std;
// Explanation
// Start DFS from each cell (i,j) in the board.
// For each cell, check if board[i][j] matches word[index].
// Mark the cell as visited by replacing it with '#' to avoid revisiting.
// Recursively explore up, down, left, right neighbors for the next character.
// If the word is found (index == word.size()), return true.
// Backtrack: restore the original character in the board.
// Complexity Analysis
// Aspect	Complexity
// Time	O(M * N * 4^L), where M = rows, N = cols, L = length of the word. Worst case, we try 4 directions at each step.
// Space	O(L) → recursion stack for word length L

class Solution {
public:
    // DFS helper function
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size()) return true; // Found the word

        // Boundary check & character match check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j]; // Save current cell
        board[i][j] = '#';       // Mark as visited

        // Explore all 4 directions
        bool found = dfs(board, word, i+1, j, index+1) ||
                     dfs(board, word, i-1, j, index+1) ||
                     dfs(board, word, i, j+1, index+1) ||
                     dfs(board, word, i, j-1, index+1);

        board[i][j] = temp; // Backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    if(s.exist(board, word)) {
        cout << "Word \"" << word << "\" exists in the board." << endl;
    } else {
        cout << "Word \"" << word << "\" does NOT exist in the board." << endl;
    }

    return 0;
}
