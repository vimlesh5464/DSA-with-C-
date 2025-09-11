#include <iostream>
#include<vector>
#include<set>
using namespace std;
// 🔹 Approaches
// 1. Brute Force
// Check all quadruplets (i, j, k, l) and see if the sum equals target.
// Use a set to avoid duplicates.
// Time Complexity: O(n⁴)
// Space Complexity: O(n) (for set)

class Solution {
  public:
      vector<vector<int>> fourSum(vector<int>& nums, int target) {
          int n = nums.size();
          set<vector<int>> st; // to avoid duplicates
          vector<vector<int>> ans;
  
          // Check all quadruplets
          for(int i = 0; i < n-3; i++){
              for(int j = i+1; j < n-2; j++){
                  for(int k = j+1; k < n-1; k++){
                      for(int l = k+1; l < n; l++){
                          if((long long)nums[i] + nums[j] + nums[k] + nums[l] == target){
                              vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                              sort(quad.begin(), quad.end()); // sort before inserting into set
                              st.insert(quad);
                          }
                      }
                  }
              }
          }
  
          // Copy from set to vector
          for(auto quad : st) ans.push_back(quad);
  
          return ans;
      }
  };


// 2. Two Pointer Approach (Optimal) ✅Idea:
// Sort the array.
// Fix the first two numbers nums[i] and nums[j].
// Use two pointers left = j+1 and right = n-1 for the remaining two numbers.
// Skip duplicates to ensure unique quadruplets.
// Time Complexity: O(n³)
// Space Complexity: O(1) (ignoring output)
class Solution {
  public:
      vector<vector<int>> fourSum(vector<int>& nums, int target) {
          int n = nums.size();
          vector<vector<int>>  ans;
          sort(nums.begin(), nums.end());
          for(int i = 0; i <n; i++){
              if(i>0 && nums[i]==nums[i-1]) continue;
              for(int j = i+1; j < n;){
                 int p = j+1, q = n-1;
                  while(p < q){
                      long long sum = (long long)nums[i]+ (long long ) nums[j]+ (long long )nums[p]+ (long long )nums[q];
                      if(sum < target){
                          p++;
                      }else if(sum > target){
                          q--;
                      }else{
                          ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                           p++; q--;
                           while(p < q && nums[p] == nums[p-1]) p++;
                      }
                  }
                  j++;
                  while(j < n && nums[j] == nums[j-1]) j++;
              }
          }
          return ans;
      }
  };

int main() {
    Solution s;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = s.fourSum(nums, target);

    for(auto &quad : res){
        cout << "[";
        for(int i = 0; i < quad.size(); i++){
            cout << quad[i];
            if(i < quad.size()-1) cout << ",";
        }
        cout << "] ";
    }
    return 0;
}
