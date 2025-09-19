#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size()) return true;

        // Boundary and character match check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j];  // Save current cell
        board[i][j] = '#';        // Mark as visited

        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp;       // Backtrack (restore original character)

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
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "Word \"" << word1 << "\" exists: " << (sol.exist(board, word1) ? "true" : "false") << endl;
    cout << "Word \"" << word2 << "\" exists: " << (sol.exist(board, word2) ? "true" : "false") << endl;
    cout << "Word \"" << word3 << "\" exists: " << (sol.exist(board, word3) ? "true" : "false") << endl;

    return 0;
}
