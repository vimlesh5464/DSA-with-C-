#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
      int maxFrequency(vector<int>& nums, int k) {
          sort(nums.begin(), nums.end());
          int maxFreq=0;
          for (int i = 0; i < nums.size(); i++) {
              long long sum = 0;
  
              for (int j = i; j < nums.size(); j++) {
                  sum += nums[j];
  
                  long long total = (long long)nums[j] * (j - i + 1);
                  long long x = total - sum;
  
                  if (x > k)
                      break;
  
                  maxFreq = max(maxFreq, j - i + 1);
              }
          }
          return maxFreq;
      }
  };

  class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
    
            long long sum = 0;
            int left = 0, ans = 0;
    
            for (int right = 0; right < nums.size(); right++) {
                sum += nums[right];
    
                // shrink window if cost exceeds k
                while ((long long)nums[right] * (right - left + 1) - sum > k) {
                    sum -= nums[left];
                    left++;
                }
    
                ans = max(ans, right - left + 1);
            }
    
            return ans;
        }
    };