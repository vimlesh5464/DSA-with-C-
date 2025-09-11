// Approach 1: Brute Force (Easy but Slow)

// For each window, find the maximum by scanning all k elements.

// Time Complexity: O(n * k)

// Space Complexity: O(1)

#include <iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        
        for (int i = 0; i <= n - k; i++) {
            int windowMax = nums[i];
            for (int j = i; j < i + k; j++) {
                windowMax = max(windowMax, nums[j]);
            }
            result.push_back(windowMax);
        }
        return result;
    }
};


// 🔹 Approach 2: Optimal using Deque

// Use deque to keep indices of useful elements.

// Always keep the deque in decreasing order of values.

// Front of deque = max in current window.

// Time Complexity: O(n)

// Space Complexity: O(k)

class Solution {
  public:
      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          deque<int> dq;  // stores indices
          vector<int> result;
          
          for (int i = 0; i < nums.size(); i++) {
              // Remove indices that are out of the window
              if (!dq.empty() && dq.front() <= i - k) {
                  dq.pop_front();
              }
              
              // Remove smaller elements from the back
              while (!dq.empty() && nums[dq.back()] < nums[i]) {
                  dq.pop_back();
              }
              
              // Add current index
              dq.push_back(i);
              
              // Start adding results once we have at least k elements
              if (i >= k - 1) {
                  result.push_back(nums[dq.front()]);
              }
          }
          return result;
      }
  };
  

int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = s.maxSlidingWindow(nums, k);
    
    for (int x : ans) cout << x << " ";
    return 0;
}
