#include<iostream>
#include <string>
#include<stack>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // base for valid substring
        int max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // new base
                } else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }

        return max_len;
    }
};

// ---------------- MAIN ----------------
int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.longestValidParentheses(s) << endl;

    return 0;
}
