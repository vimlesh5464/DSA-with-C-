// Given string num representing a non-negative integer num, and an integer k, return the 
//smallest possible integer after removing k digits from num.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the 
//smallest.

// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not 
//contain leading zeroes.

// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

 

// Constraints:

//     1 <= k <= num.length <= 105
//     num consists of only digits.
//     num does not have any leading zeros except for the zero itself.

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
