
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
      int findKthLargest(vector<int>& nums, int k) {
           int n = nums.size();
  
      // Create a min heap (priority queue)
      priority_queue<int, vector<int>, greater<int>> pq;
  
      // Iterate through the array elements
      for (int i = 0; i < n; i++) {
  
          // Push the current element onto the min heap
          pq.push(nums[i]);
  
          // If the size of the min heap exceeds K,
          // remove the largest element
          if (pq.size() > k)
              pq.pop();
      }
  
      // Return the Kth largest element (top of the min heap)
      return pq.top();
      }
  };