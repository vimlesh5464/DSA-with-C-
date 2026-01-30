#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;

class Solution {
  public:
      // Function to return the length of the longest substring that can be made of repeating characters
      // by replacing at most k characters
      int characterReplacement(string s, int k) {
          
          // Map to count frequency of characters in current window
          unordered_map<char, int> freq;
  
          // Left pointer of the sliding window
          int left = 0;
  
          // Tracks the count of the most frequent character in the window
          int max_freq = 0;
  
          // Stores the result (maximum length found)
          int max_len = 0;
  
          // Traverse the string with right pointer
          for (int right = 0; right < s.length(); right++) {
  
              // Increase frequency of the current character
              freq[s[right]]++;
  
              // Update max frequency seen so far in the window
              max_freq = max(max_freq, freq[s[right]]);
  
              // If window is invalid (needs more than k replacements)
              while ((right - left + 1) - max_freq > k) {
  
                  // Decrease frequency of the character at left
                  freq[s[left]]--;
  
                  // Shrink the window from the left
                  left++;
              }
  
              // Update max_len with current valid window size
              max_len = max(max_len, right - left + 1);
          }
  
          // Return the final result
          return max_len;
      }
  };
class Solution {
public:
    // Function to return the length of the longest substring that can be made of repeating characters
    // by replacing at most k characters
    int characterReplacement(string s, int k) {
        // Frequency array for A-Z
        vector<int> freq(26, 0);
        
        // Left and right pointers of sliding window
        int left = 0, right = 0;

        // Tracks the count of the most frequent character in current window
        int maxCount = 0;

        // Stores the maximum length of valid window
        int maxLength = 0;

        // Iterate through the string with right pointer
        while (right < s.size()) {

            // Increment the frequency of current character
            freq[s[right] - 'A']++;

            // Update maxCount with the max frequency seen so far
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // If the current window needs more than k replacements, move left
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update the maximum window length
            maxLength = max(maxLength, right - left + 1);
            
            // Move right pointer forward
            right++;
        }

        // Return the maximum valid window length
        return maxLength;
    }
};

// Driver code
int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    // Output: 4
    cout << sol.characterReplacement(s, k) << endl; 
    return 0;
}


