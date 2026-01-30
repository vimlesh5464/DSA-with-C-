#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;

        // Step 1: Monotonic increasing stack
        for (int i = 0; i < n; i++) {
            while (!s.empty() && k > 0 && s.top() > num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }

        // Step 2: Remove remaining digits from end if k > 0
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        // Step 3: If stack is empty
        if (s.empty()) {
            return "0";
        }

        // Step 4: Build result string
        string res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());

        // Step 5: Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }
        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};

int main() {
    string num;
    int k;

    // Input
    cout << "Enter number: ";
    cin >> num;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    string ans = obj.removeKdigits(num, k);

    // Output
    cout << "Smallest number after removing k digits: " << ans << endl;

    return 0;
}
