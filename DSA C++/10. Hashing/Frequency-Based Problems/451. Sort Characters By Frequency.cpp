// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

 

// Constraints:

//     1 <= s.length <= 5 * 105
//     s consists of uppercase and lowercase English letters and digits.



#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Move to vector
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Step 3: Sort by frequency
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 4: Build result
        string result = "";
        for (auto &p : vec) {
            result += string(p.second, p.first);
        }

        return result;
    }
};

#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s) freq[c]++;

        priority_queue<pair<int, char>> maxHeap;

        for (auto &p : freq) {
            maxHeap.push({p.second, p.first});
        }

        string result = "";

        while (!maxHeap.empty()) {
            auto [f, c] = maxHeap.top();
            maxHeap.pop();

            result += string(f, c);
        }

        return result;
    }
};

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Bucket
        vector<string> bucket(s.size() + 1);

        for (auto &p : freq) {
            int f = p.second;
            bucket[f] += string(f, p.first);
        }

        // Build result
        string result = "";
        for (int i = s.size(); i >= 1; i--) {
            result += bucket[i];
        }

        return result;
    }
};