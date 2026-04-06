# 377. Combination Sum IV.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array of distinct integers nums and a target integer target, 
# //return the number of possible combinations that add up to target.
# 
# // The test cases are generated so that the answer can fit in a 32-bit integer.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,2,3], target = 4
# // Output: 7
# // Explanation:
# // The possible combination ways are:
# // (1, 1, 1, 1)
# // (1, 1, 2)
# // (1, 2, 1)
# // (1, 3)
# // (2, 1, 1)
# // (2, 2)
# // (3, 1)
# // Note that different sequences are counted as different combinations.
# 
# // Example 2:
# 
# // Input: nums = [9], target = 3
# // Output: 0
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 200
# //     1 <= nums[i] <= 1000
# //     All the elements of nums are unique.
# //     1 <= target <= 1000
# 
# #include<iostream>
# #include<vector>
# using namespace std;
# int combi(vector<int>& nums,int i,vector<int>&subset,vector<vector<int>>&ans,int target){
#   
#   if(i==nums.size()){
#     if(target==0){
#       ans.push_back(subset);
#       return 1;
#     }
#     
#   }
# if(i==nums.size() || target<0){
#   return 0;
# }
# 
# subset.push_back(nums[i]);
# int include = combi(nums,i,subset,ans,target-nums[i]);
# subset.pop_back();
# 
# int exclude=combi(nums,i+1,subset,ans,target);
# return include+exclude;
# }
# int main(){
#   vector<int> subset;
#   int target = 2;
#   vector<int> nums={1,2,3};
#   vector<vector<int>> ans;
#   int count = combi(nums,0,subset,ans,target);
#   cout<< "count: "<<count<<endl;
#   for(int i = 0; i < ans.size(); i++){
#     for(int j = 0; j < ans[i].size(); j++){
#       cout<<ans[i][j];
#     }
#     cout<<endl;
#   }
#   return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
