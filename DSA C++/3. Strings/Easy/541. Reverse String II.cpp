// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

// Example 1:

// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"

// Example 2:

// Input: s = "abcd", k = 2
// Output: "bacd"

 

// Constraints:

//     1 <= s.length <= 104
//     s consists of only lowercase English letters.
//     1 <= k <= 104

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {

            int left = i;
            int right = min(i + k - 1, (int)s.length() - 1);

            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    string result = sol.reverseStr(s, k);
    cout << "Output: " << result << endl;

    return 0;
}
