# 128. Longest Consecutive Sequence.py - Python skeleton converted from C++

# Original C++ code:
# // Given an unsorted array of integers nums, return the length of the longest 
# //consecutive elements sequence.
# 
# // You must write an algorithm that runs in O(n) time.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [100,4,200,1,3,2]
# // Output: 4
# // Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
# //Therefore its length is 4.
# 
# // Example 2:
# 
# // Input: nums = [0,3,7,2,5,8,4,6,0,1]
# // Output: 9
# 
# // Example 3:
# 
# // Input: nums = [1,0,1,2]
# // Output: 3
# 
#  
# 
# // Constraints:
# 
# //     0 <= nums.length <= 105
# //     -109 <= nums[i] <= 109
# #include<iostream>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#       int longestConsecutive(vector<int>& nums) {
#           if(nums.empty()) return 0;
#   
#           sort(nums.begin(), nums.end());
#           int count = 1;
#           int max_count = 1;
#   
#           for(int i = 1; i < nums.size(); i++){
#               if(nums[i] == nums[i-1]) continue; // skip duplicate
#               else if(nums[i] - nums[i-1] == 1) count++;
#               else count = 1; // reset count for non-consecutive
#   
#               max_count = max(max_count, count);
#           }
#   
#           return max_count;
#       }
#   };
#   #include <vector>
# #include <unordered_set>
# using namespace std;
# 
# class Solution {
# public:
#     int longestConsecutive(vector<int>& nums) {
#         unordered_set<int> numSet(nums.begin(), nums.end());
#         int maxLength = 0;
# 
#         for(int num : nums){
#             // check if it's the start of a sequence
#             if(numSet.find(num - 1) == numSet.end()){
#                 int currentNum = num;
#                 int currentLength = 1;
# 
#                 while(numSet.find(currentNum + 1) != numSet.end()){
#                     currentNum++;
#                     currentLength++;
#                 }
# 
#                 maxLength = max(maxLength, currentLength);
#             }
#         }
# 
#         return maxLength;
#     }
# };
#  int main(){
#   Solution s;
#   vector<int> nums = {100,4,200,1,3,2};
#   cout<<s.longestConsecutive(nums);
#   return 0;
#  }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
