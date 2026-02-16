#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size()) return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    int m, n;
    cout << "Enter number of rows and columns of the board: ";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    cout << "Enter the board characters row by row (space separated):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int t;
    cout << "Enter number of words to search: ";
    cin >> t;

    for (int k = 0; k < t; k++) {
        string word;
        cout << "Enter word " << k + 1 << ": ";
        cin >> word;

        cout << "Word \"" << word << "\" exists: "
             << (sol.exist(board, word) ? "true" : "false") << endl;
    }

    return 0;
}
