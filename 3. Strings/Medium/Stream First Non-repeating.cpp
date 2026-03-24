// Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

// Examples:

// Input: s = "aabc"
// Output: a#bb
// Explanation: 
// At i=0 ("a"): First non-repeating character is 'a'.
// At i=1 ("aa"): No non-repeating character, so '#'.
// At i=2 ("aab"): First non-repeating character is 'b'.
// At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'. 

// Input: s = "bb" 
// Output: "b#" 
// Explanation: 
// At i=0 ("b"): First non-repeating character is 'b'.
// At i=1 ("bb"): No non-repeating character, so '#'.
#include <iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";

        for (char ch : s) {
            freq[ch - 'a']++;
            q.push(ch);

            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if (q.empty()) {
                ans.push_back('#');
            } else {
                ans.push_back(q.front());
            }
        }

        return ans;
    }
};