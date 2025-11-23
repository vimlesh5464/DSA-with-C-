#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Backtracking function to generate valid IP segments
    void backtrack(string s, vector<string>& ans, int num, string temp) {
        // If we already have 4 parts
        if (num == 4) {
            // Check if string is fully consumed
            if (s.empty()) {
                temp.pop_back(); // Remove last '.'
                ans.push_back(temp);
            }
            return;
        }

        // If string is empty but we don't have 4 parts yet
        if (s.empty()) return;

        // Case 1: Leading zero (can only be "0")
        if (s[0] == '0') {
            backtrack(s.substr(1), ans, num + 1, temp + "0.");
        } 
        else {
            // Case 2: Try segments of length 1, 2, or 3
            for (int i = 0; i < s.size() && i < 3; i++) {
                string curr = s.substr(0, i + 1);
                int val = stoi(curr);
                if (val > 0 && val <= 255) {
                    backtrack(s.substr(i + 1), ans, num + 1, temp + curr + ".");
                } else {
                    return; // stop exploring further (e.g., >255)
                }
            }
        }
    }

    // Main function to restore IP addresses
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.empty()) return ans;
        backtrack(s, ans, 0, "");
        return ans;
    }
};

int main() {
    Solution obj;
    string s;
    cout << "Enter a numeric string: ";
    cin >> s;

    vector<string> result = obj.restoreIpAddresses(s);

    cout << "\nPossible valid IP addresses:\n";
    for (auto& ip : result) {
        cout << ip << endl;
    }

    return 0;
}
