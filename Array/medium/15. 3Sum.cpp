#include <iostream>
#include<vector>
#include<set>
using namespace std;
// 🔹 Approaches
// 1. Brute Force
//     Check all triplets (i, j, k) and see if nums[i] + nums[j] + nums[k] == 0.
//     Use a set to avoid duplicates.
// Time Complexity: O(n³)
// Space Complexity: O(n) (for set)
class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          int n = nums.size();
          set<vector<int>> st;  // To avoid duplicates
          vector<vector<int>> ans;
  
          // Check all triplets
          for(int i = 0; i < n-2; i++){
              for(int j = i+1; j < n-1; j++){
                  for(int k = j+1; k < n; k++){
                      if(nums[i] + nums[j] + nums[k] == 0){
                          vector<int> triplet = {nums[i], nums[j], nums[k]};
                          sort(triplet.begin(), triplet.end()); // Sort before inserting into set
                          st.insert(triplet);
                      }
                  }
              }
          }
  
          // Copy from set to vector
          for(auto triplet : st) ans.push_back(triplet);
  
          return ans;
      }
  };
  
// 2. Two Pointer Approach (Optimal) ✅Idea:
// Sort the array.
// Fix the first element nums[i].
// Use two pointers, left = i+1 and right = n-1, to find pairs such that nums[i] + nums[left] + nums[right] == 0.
// Skip duplicates to ensure unique triplets.
// Time Complexity: O(n²)
// Space Complexity: O(1) (ignoring output)


class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          int n = nums.size();
          vector<vector<int>> ans;
          sort(nums.begin(), nums.end());
  
          for(int i = 0; i < n; i++){
              if(i>0 && nums[i]==nums[i-1]) continue;
  
              int j = i+1, k = n-1;
              while(j < k){
                  int sum = nums[i] + nums[j] + nums[k];
                  if(sum < 0){
                      j++;
                  } else if(sum > 0){
                      k--;
                  } else {
                      ans.push_back({nums[i], nums[j], nums[k]});
                      j++; k--;
  
                      // Skip duplicates
                      while(j < k && nums[j] == nums[j-1]) j++;
                      while(j < k && nums[k] == nums[k+1]) k--;
                  }
              }
          }
          return ans;
      }
  };
  
int main() {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = s.threeSum(nums);

    for(auto &triplet : res){
        cout << "[";
        for(int i = 0; i < triplet.size(); i++){
            cout << triplet[i];
            if(i < triplet.size()-1) cout << ",";
        }
        cout << "] ";
    }
    return 0;
}
