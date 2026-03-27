#include <iostream>
#include <vector>
#include<unordered_map>
#include <string>
using namespace std;
class Solution {
  public:
      // Function to find the length of the longest substring with at most K distinct characters
      int lengthOfLongestSubstringKDistinct(string s, int k) {
          // Store the maximum length of valid substring
          int maxLength = 0;
  
          // Try every possible substring
          for (int i = 0; i < s.size(); i++) {
              // Use set/map to track distinct characters in current substring
              unordered_map<char, int> freq;
  
              for (int j = i; j < s.size(); j++) {
                  // Add current character to map and update frequency
                  freq[s[j]]++;
  
                  // If number of distinct characters exceeds k, break
                  if (freq.size() > k) break;
  
                  // Update maximum length if valid
                  maxLength = max(maxLength, j - i + 1);
              }
          }
  
          // Return the maximum valid substring length
          return maxLength;
      }
  };
  
  class Solution {
    public:
        int longestKSubstr(string &s, int k) {
            if (k == 0 || s.empty()) return -1;
    
            unordered_map<char, int> freq;
            int left = 0, maxLen = -1;
    
            for (int right = 0; right < s.size(); right++) {
                freq[s[right]]++;
    
                // Shrink window if number of distinct characters exceeds k
                while (freq.size() > k) {
                    freq[s[left]]--;
                    if (freq[s[left]] == 0) freq.erase(s[left]);
                    left++;
                }
    
                // Update maxLen only if window has exactly k distinct characters
                if (freq.size() == k) {
                    maxLen = max(maxLen, right - left + 1);
                }
            }
    
            return maxLen;  // -1 if no substring with exactly k distinct characters
        }
    };
    
  // Driver code
  int main() {
      Solution sol;
      string s = "eceba";
      int k = 2;
  
      cout << sol.longestKSubstr(s, k) << endl;
      return 0;
  }