#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      // Check if a subarray is Trionic: increase → decrease → increase
      bool isTrionic(const vector<int>& sub) {
          int n = sub.size();
          if (n < 3) return false; // minimum 3 elements needed
  
          int i = 0;
  
          // 1️⃣ strictly increasing phase
          while (i + 1 < n && sub[i] < sub[i + 1]) i++;
          if (i == 0) return false; // must have at least one increasing step
  
          // 2️⃣ strictly decreasing phase
          int j = i;
          while (j + 1 < n && sub[j] > sub[j + 1]) j++;
          if (j == i) return false; // must have at least one decreasing step
  
          // 3️⃣ strictly increasing phase
          int k = j;
          while (k + 1 < n && sub[k] < sub[k + 1]) k++;
          if (k == j) return false; // must have at least one increasing step
  
          // must reach end of subarray
          return k == n - 1;
      }
  
      // Brute-force: check all subarrays
      long long maxSumTrionic(vector<int>& nums) {
          int n = nums.size();
          long long maxSum = LLONG_MIN; // initialize to smallest for negatives
  
          for (int i = 0; i < n; i++) {
              for (int j = i + 2; j < n; j++) { // subarray length >= 3
                  vector<int> sub(nums.begin() + i, nums.begin() + j + 1);
  
                  if (isTrionic(sub)) {
                      long long sum = 0;
                      for (int x : sub) sum += x;
                      maxSum = max(maxSum, sum);
                  }
              }
          }
  
          // If no trionic subarray exists, return 0
          return (maxSum == LLONG_MIN) ? 0 : maxSum;
      }
  };
  


class Solution {
  public:
      vector<tuple<int, int, long long> > decompose(vector<int>& nums){
          int n = (int)nums.size();
          vector<tuple<int, int, long long> > subarrays;
  
          int l = 0;
          long long sum = nums[0];
          
          for(int i = 1; i < n; i ++){
              // If we fail strict decreasing at boundary i-1 -> i, end the current subarray.
              if(nums[i - 1] <= nums[i]){
                  subarrays.push_back({l, i - 1, sum});
                  l = i;
                  sum = 0;
              }
              sum += nums[i];
          }
          //last subarray
          subarrays.push_back({l, n - 1, sum});
          return subarrays;
      }
      long long maxSumTrionic(vector<int>& nums){
          int n = (int)nums.size();
          long long maxEndingAt[n];
          for(int i = 0; i < n; i ++){
              maxEndingAt[i] = nums[i];
              if(i > 0 && nums[i - 1] < nums[i]){
                  if(maxEndingAt[i - 1] > 0){
                      maxEndingAt[i] += maxEndingAt[i - 1];
                  }
              }
          }
          long long maxStartingAt[n];
          for(int i = n - 1; i >= 0; i --){
              maxStartingAt[i] = nums[i];
              if(i < n - 1 && nums[i] < nums[i + 1]){
                  if(maxStartingAt[i + 1] > 0){
                      maxStartingAt[i] += maxStartingAt[i + 1];
                  }
              }
          }
          vector<tuple<int, int, long long> > PQS = decompose(nums);
          long long ans = LLONG_MIN;
          for(auto [p, q, sum] : PQS){
              
              if(p > 0 && nums[p-1] < nums[p] &&
                 q < n - 1 && nums[q] < nums[q + 1] &&
                 p < q){
                  ans = max(ans, maxEndingAt[p-1] + sum + maxStartingAt[q+1]);
              }
          }
          return ans;
      }
  };