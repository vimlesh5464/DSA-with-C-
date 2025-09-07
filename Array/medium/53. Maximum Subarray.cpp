
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//🔹 Approaches
//1. Brute Force (Check All Subarrays)
// Time Complexity: O(n²) or O(n³)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

//2. Kadane’s Algorithm (Optimal) ✅
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
  public:
      int maxSubArray(vector<int>& nums) {
          int maxSum = nums[0];
          int currentSum = nums[0];
          for(int i = 1; i < nums.size(); i++){
              currentSum = max(nums[i], currentSum + nums[i]);
              maxSum = max(maxSum, currentSum);
          }
          return maxSum;
      }
  };
int main() {
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum Subarray Sum: " << s.maxSubArray(nums) << endl;
    return 0;
}
