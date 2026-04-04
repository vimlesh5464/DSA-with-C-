// Given a collection of numbers, nums, that might contain duplicates, return all possible 
//unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 

// Constraints:

//     1 <= nums.length <= 8
//     -10 <= nums[i] <= 10

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
  public:
      void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds,
                  vector<int>& freq) {
  
          int n = nums.size();
  
          if (ds.size() == n) {
              ans.push_back(ds);
              return;
          }
  
          for (int i = 0; i < n; i++) {
  
              if (freq[i])
                  continue;
  
              // 🔥 Correct duplicate condition
              if (i > 0 && nums[i] == nums[i - 1] && freq[i - 1] == 0)
                  continue;
  
              ds.push_back(nums[i]);
              freq[i] = 1;
  
              helper(nums, ans, ds, freq);
  
              ds.pop_back();
              freq[i] = 0;
          }
      }
  
      vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>> ans;
          vector<int> ds;
          vector<int> freq(nums.size(), 0);
  
          sort(nums.begin(), nums.end()); // very important
  
          helper(nums, ans, ds, freq);
  
          return ans;
      }
  };
class Solution {
  public:
      void helper(vector<int>& nums, int ind, vector<vector<int>>& ans) {
          if (ind == nums.size()) {
              ans.push_back(nums);
              return;
          }
           unordered_set<int> used; 
          for (int i = ind; i < nums.size(); i++) {
              if (used.count(nums[i])) continue;
  
              used.insert(nums[i]);
              swap(nums[ind], nums[i]);
              helper(nums, ind + 1, ans);
              swap(nums[ind], nums[i]);
          }
      }
      vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>> ans;
          sort(nums.begin(),nums.end());
          helper(nums, 0, ans);
          return ans;
      }
  };

  class Solution {
    public:
    
        void get(string& s, int ind, vector<string> &result) {
    
            // ✅ Base case
            if (ind == s.size()) {
                result.push_back(s);
                return;
            }
    
            // 🔥 Set to avoid duplicate swaps at same level
            unordered_set<char> used;
    
            for (int i = ind; i < s.size(); i++) {
    
                // ❌ Skip if already used at this level
                if (used.count(s[i])) continue;
                used.insert(s[i]);
    
                // 🔁 Swap
                swap(s[ind], s[i]);
    
                // 🔁 Recurse
                get(s, ind + 1, result);
    
                // 🔙 Backtrack
                swap(s[ind], s[i]);
            }
        }
    
        vector<string> findPermutation(string &s) {
    
            vector<string> result;
    
            // 🔥 Optional but good for ordered output
            sort(s.begin(), s.end());
    
            get(s, 0, result);
    
            return result;
        }
    };