#include<iostream>
#include<vector>
#include<string>
using namespace std;

// ⏱ Time Complexity: O(4^n / sqrt(n)) (Catalan number growth)
// 📦 Space Complexity: O(n) (recursion depth)
class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // If the current string is of length 2*n, it's a valid parentheses combination
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add an open parenthesis if possible
        if (open < n) {
            backtrack(result, current + '(', open + 1, close, n);
        }

        // Add a close parenthesis if valid
        if (close < open) {
            backtrack(result, current + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);

    cout << "All valid parentheses combinations for n=" << n << ":\n";
    for (string s : ans) {
        cout << s << "\n";
    }

    return 0;
}
