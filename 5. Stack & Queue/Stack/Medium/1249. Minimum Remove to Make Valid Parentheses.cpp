#include<iostream>
#include <string>
#include<stack>
using namespace std;


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0; // counts unmatched '('
        string temp;

        // 1️⃣ First pass: remove extra ')'
        for (char c : s) {
            if (c == '(') {
                balance++;
                temp += c;
            } else if (c == ')') {
                if (balance > 0) {
                    balance--;
                    temp += c;
                }
                // else skip this ')'
            } else {
                temp += c; // normal character
            }
        }

        // 2️⃣ Second pass: remove extra '(' from end
        string result;
        int openToKeep = balance; // extra '(' to remove
        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && openToKeep > 0) {
                openToKeep--;
                continue; // skip this '('
            }
            result += temp[i];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// ---------------- MAIN ----------------
int main() {
    string s;
    getline(cin, s); // read full line including spaces

    Solution sol;
    string valid = sol.minRemoveToMakeValid(s);

    cout << valid << endl;

    return 0;
}
