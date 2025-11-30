#include<iostream>
#include <string>
#include<stack>
using namespace std;


class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, res = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else { // c == ')'
                if (balance > 0) balance--;
                else res++;
            }
        }
        return res + balance;
    }
};

// ---------------- MAIN ----------------
int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minAddToMakeValid(s) << endl;

    return 0;
}
