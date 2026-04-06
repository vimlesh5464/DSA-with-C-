# 643. Maximum Average Subarray I.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# class Solution {
# public:
#     double findMaxAverage(vector<int>& nums, int k) {
#         long long windowSum = 0;
# 
#         // Sum of first k elements
#         for (int i = 0; i < k; i++) {
#             windowSum += nums[i];
#         }
# 
#         long long maxSum = windowSum;
# 
#         // Sliding window
#         for (int i = k; i < nums.size(); i++) {
#             windowSum += nums[i];
#             windowSum -= nums[i - k];
#             maxSum = max(maxSum, windowSum);
#         }
# 
#         return (double)maxSum / k;
#     }
# };
# 
# int main() {
#     Solution obj;
# 
#     vector<int> nums = {1, 12, -5, -6, 50, 3};
#     int k = 4;
# 
#     double result = obj.findMaxAverage(nums, k);
#     cout  << result << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
