
#include <iostream>
#include<vector>
using namespace std;
//Time & Space Complexity:O(n) → each character is visited at most twice and O(1) → mpp size = 256, constant
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1); // stores last index of each character

        int left = 0, right = 0;
        int n = s.size();
        int len = 0;

        while (right < n) {
            // If current character is repeated, move left pointer
            if (mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left);

            // Update last index of current character
            mpp[s[right]] = right;

            // Update max length
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};

int main() {
    Solution s;
    string str = "abcabcbb";
    int res = s.lengthOfLongestSubstring(str);
    cout << "Length of Longest Substring Without Repeating Characters: " << res << endl;
    return 0;
}
