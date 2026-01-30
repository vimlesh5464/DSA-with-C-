#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

class Solution {
  public:
      long long maximumSubarraySum(vector<int>& nums, int k) {
          int n = nums.size();
          long long maxSum = 0;
  
          for(int i = 0; i <= n - k; i++) {
              unordered_set<int> st;
              long long sum = 0;
              bool valid = true;
  
              for(int j = i; j < i + k; j++) {
                  if(st.count(nums[j])) {
                      valid = false;
                      break;
                  }
                  st.insert(nums[j]);
                  sum += nums[j];
              }
  
              if(valid) {
                  maxSum = max(maxSum, sum);
              }
          }
  
          return maxSum;
      }
  };

//   Time	O(n) → each element added/removed at most once
// Space	O(k) → hash set for window
class Solution {
  public:
      long long maximumSubarraySum(vector<int>& nums, int k) {
          unordered_set<int> st;
          long long sum = 0, maxSum = 0;
          int left = 0;
  
          for(int right = 0; right < nums.size(); right++) {
  
              // Remove duplicates
              while(st.count(nums[right])) {
                  sum -= nums[left];
                  st.erase(nums[left]);
                  left++;
              }
  
              // Add current element
              st.insert(nums[right]);
              sum += nums[right];
  
              // Window size exactly k
              if(st.size() == k) {
                  maxSum = max(maxSum, sum);
  
                  // Slide window
                  sum -= nums[left];
                  st.erase(nums[left]);
                  left++;
              }
          }
          return maxSum;
      }
  };
  
  int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.maximumSubarraySum(nums, k) << endl;

    return 0;
}