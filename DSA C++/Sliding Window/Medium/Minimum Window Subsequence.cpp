// You are given two strings, s1 and s2. Your task is to find the smallest substring in s1 such that s2 appears as a subsequence within that substring.

//     The characters of s2 must appear in the same sequence within the substring of s1.
//     If there are multiple valid substrings of the same minimum length, return the one that appears first in s1.
//     If no such substring exists, return an empty string.

// Note: Both the strings contain only lowercase english letters.

// Examples:

// Input: s1 = "geeksforgeeks", s2 = "eksrg"
// Output: "eksforg"
// Explanation: "eksforg" satisfies all required conditions. s2 is its subsequence and it is smallest and leftmost among all possible valid substrings of s1.

// Input: s1 = "abcdebdde", s2 = "bde" 
// Output: "bcde"
// Explanation:  "bcde" and "bdde" are two substring of s1 where s2 occurs as subsequence but "bcde" occur first so we return that.

// Input: s1 = "ad", s2 = "b" 
// Output: ""
// Explanation: There is no substring exists.

// Constraints:
// 1 ≤ s1.length ≤ 104
// 1 ≤ s2.length ≤ 50


#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size(), m = s2.size();
    int minLen = INT_MAX;
    string ans = "";

    int i = 0;
    while (i < n) {
        int j = 0;

        // Step 1: Move forward to match s2
        while (i < n) {
            if (s1[i] == s2[j]) j++;
            if (j == m) break;
            i++;
        }

        if (j != m) break;  // s2 not found

        // Step 2: Backtrack to minimize window
        int end = i;
        j = m - 1;
        while (i >= 0) {
            if (s1[i] == s2[j]) j--;
            if (j < 0) break;
            i--;
        }

        int start = i;
        if (end - start + 1 < minLen) {
            minLen = end - start + 1;
            ans = s1.substr(start, minLen);
        }

        i = start + 1; // move forward for next window
    }

    return ans;
    }
};
