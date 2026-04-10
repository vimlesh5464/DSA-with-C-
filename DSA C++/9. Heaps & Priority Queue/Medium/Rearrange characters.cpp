// Given a string s with repeated characters, the task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them. If there is no possible solution, then print empty string ("").

// Examples:

// Input : s = "aaabc"
// Output: 1
// Explanation: "aaabc" can rearranged to "abaca" or "acaba" as no two adjacent characters are same in the output string.

// Input : s= "aaabb"
// Output: 1
// Explanation: "aaabb" can rearranged to "ababa" as no two adjacent characters are same in the output string.

// Input : s = "aaaabc"
// Output: 0
// Explanation: No combinations possible such that two adjacent characters are different.

// Constraints :
// 1 <= s.size() <= 104


#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string rearrangeString(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Max Heap (freq, char)
        priority_queue<pair<int, char>> maxHeap;
        for (auto &p : freq) {
            maxHeap.push({p.second, p.first});
        }

        string result = "";

        while (maxHeap.size() > 1) {
            auto [f1, c1] = maxHeap.top(); maxHeap.pop();
            auto [f2, c2] = maxHeap.top(); maxHeap.pop();

            // Add both chars
            result += c1;
            result += c2;

            // Decrease freq
            if (--f1 > 0) maxHeap.push({f1, c1});
            if (--f2 > 0) maxHeap.push({f2, c2});
        }

        // If one char left
        if (!maxHeap.empty()) {
            auto [f, c] = maxHeap.top();

            if (f > 1) return ""; // not possible
            result += c;
        }

        return result;
    }
};