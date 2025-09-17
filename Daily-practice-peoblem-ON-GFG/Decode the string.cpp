// Decode the string
// Difficulty: MediumAccuracy: 44.28%Submissions: 63K+Points: 4Average Time: 10m

// Given an encoded string s, decode it by expanding the pattern k[substring], where the substring inside brackets is written k times. k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets. Return the final decoded string.

// Note: The test cases are generated so that the length of the output string will never exceed 105 .

// Examples:

// Input: s = "3[b2[ca]]"
// Output: "bcacabcacabcaca"
// Explanation:
// Inner substring “2[ca]” breakdown into “caca”.
// Now, new string becomes “3[bcaca]”
// Similarly “3[bcaca]” becomes “bcacabcacabcaca” which is final result.

// Input: s = "3[ab]"
// Output: "ababab"
// Explanation: The substring "ab" is repeated 3 times giving "ababab".

// Constraints:
// 1 ≤ |s| ≤ 105 
// 1 ≤ k ≤ 100

#include <iostream>
#include <cmath>     
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // build number (could be multi-digit)
            } 
            else if (c == '[') {
                countStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            } 
            else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string prev = strStack.top(); strStack.pop();

                string temp = "";
                for (int i = 0; i < repeat; i++) temp += curr;

                curr = prev + temp;
            } 
            else {
                curr += c; // add normal character
            }
        }
        return curr;
    }
};

int main() {
    Solution sol;

    string s1 = "3[b2[ca]]";
    cout << "Input: " << s1 << "\n";
    cout << "Output: " << sol.decodeString(s1) << "\n\n";

    string s2 = "3[ab]";
    cout << "Input: " << s2 << "\n";
    cout << "Output: " << sol.decodeString(s2) << "\n\n";

    string s3 = "2[a2[b]c]";
    cout << "Input: " << s3 << "\n";
    cout << "Output: " << sol.decodeString(s3) << "\n";

    return 0;
}
