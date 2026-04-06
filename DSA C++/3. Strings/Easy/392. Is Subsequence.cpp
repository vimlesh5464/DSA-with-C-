// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the 
//original string by deleting some (can be none) of the characters without 
//disturbing the relative positions of the remaining characters. 
//(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

 

// Constraints:

//     0 <= s.length <= 100
//     0 <= t.length <= 104
//     s and t consist only of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t
        
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++; // match found in order
            }
            j++; // always move in t
        }
        
        return i == s.size(); // all characters matched?
    }
};

int main() {
    string s, t;
    
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;
    
    Solution obj;
    bool result = obj.isSubsequence(s, t);
    
    if(result) {
        cout << "YES, s is a subsequence of t\n";
    } else {
        cout << "NO, s is NOT a subsequence of t\n";
    }

    return 0;
}
