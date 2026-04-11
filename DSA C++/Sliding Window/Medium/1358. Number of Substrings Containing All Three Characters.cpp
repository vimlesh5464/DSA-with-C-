// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

// Example 3:

// Input: s = "abc"
// Output: 1

 

// Constraints:

//     3 <= s.length <= 5 x 10^4
//     s only consists of a, b or c characters.


#include <iostream>
#include<vector>
using namespace std;
//Time Complexity: O(n²), where n is the length of the input string.We iterate through all possible starting indices from 0 to n−1, and for each starting index, we traverse the substring until we find a valid one (containing at least one 'a', 'b', and 'c'). In the worst case, the inner loop can run up to n times for each outer loop iteration, leading to a total of O(n²) operations.

//Space Complexity: O(1), constant space.We use a frequency map of fixed size (only for characters 'a', 'b', and 'c'). Regardless of input size, the space used remains constant. Hence, space complexity is O(1).
class Solution {
public:
    // Function to count substrings containing at least one 'a', one 'b', and one 'c'
    int numberOfSubstrings(string s) {
        // Variable to store the final count
        int count = 0;
        // Length of the input string
        int n = s.length();

        // Outer loop to fix the start of the substring
        for (int i = 0; i < n; i++) {
            // Array to track the count of 'a', 'b', and 'c'
            vector<int> freq(3, 0);

            // Inner loop to fix the end of the substring
            for (int j = i; j < n; j++) {
                // Update frequency for current character
                freq[s[j] - 'a']++;

                // Check if all three characters are present
                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                    // Add valid substring
                    count++;
                }
            }
        }
        return count;
    }
};

//Time Complexity:O(n) ,We traverse the string once with the right pointer and adjust the left pointer in a linear pass. Each character is processed at most twice (once by the right pointer and once by the left), resulting in linear time complexity.

//Space Complexity: O(1),We only use a constant-size frequency array for three characters ('a', 'b', 'c'), hence the space usage does not grow with input size.
class Solution {
public:
    // Function to count substrings containing at least one 'a', 'b', and 'c' using sliding window
    int numberOfSubstrings(string s) {
        // Initialize frequency map for 'a', 'b', and 'c'
        vector<int> freq(3, 0);

        // Initialize result to store count of valid substrings
        int res = 0;

        // Initialize left pointer of the sliding window
        int left = 0;

        // Traverse the string using right pointer
        for (int right = 0; right < s.length(); right++) {
            // Increment frequency of current character
            freq[s[right] - 'a']++;

            // Shrink the window from the left while all three characters are present
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Count all substrings from current right to end
                res += (s.length() - right);

                // Decrease frequency of character at left and move left forward
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return res;
    }
};

