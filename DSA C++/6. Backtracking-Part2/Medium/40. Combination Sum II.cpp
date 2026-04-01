// Given a collection of candidate numbers (candidates) and a target number (target), 
//find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.
// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
// Constraints:

//     1 <= candidates.length <= 100
//     1 <= candidates[i] <= 50
//     1 <= target <= 30

 

#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
using namespace std;

class Solution {
  public:
  void helper(vector<int>& candidates,int target,int i,vector<int>&subset,set<vector<int>>&ans){
      
          if(target==0){
              ans.insert(subset);
              return;
          }
          
      
  
      if(i==candidates.size() || target<0){
          return;
      }
  
      subset.push_back(candidates[i]);
      helper(candidates,target-candidates[i],i+1,subset,ans);
      subset.pop_back();
      helper(candidates,target,i+1,subset,ans);
  }
      vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(), candidates.end()); 
          set<vector<int>> ans;
          vector<int> subset;
          helper(candidates,target,0,subset,ans);
          vector<vector<int>> ans1(ans.begin(),ans.end());
          return ans1;
      }
  };

  class Solution {
    public:
        void helper(vector<int>& candidates, int target, int start, vector<int>& subset,
                    vector<vector<int>>& ans) {
            if (target == 0) {
                ans.push_back(subset);
                return;
            }
    
            for (int i = start; i < candidates.size(); i++) {
                // skip duplicates at the same recursion level
                if (i > start && candidates[i] == candidates[i-1]) continue;
    
                // if the current number exceeds target, break
                if (candidates[i] > target) break;
    
                subset.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i + 1, subset, ans);
                subset.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> subset;
            helper(candidates, target, 0, subset, ans);
            return ans;
        }
    };
    class Solution {
      public:
          void helper(vector<int>& candidates, int target, int start, vector<int>& subset,
                      vector<vector<int>>& ans) {
              if (target == 0) {
                  ans.push_back(subset);
                  return;
              }
              unordered_set<int>seen;
              for (int i = start; i < candidates.size(); i++) {
                  if(seen.find(candidates[i])!=seen.end()){
                      continue;
                  }
                  if (candidates[i] > target) break;
                  seen.insert(candidates[i]);
                  subset.push_back(candidates[i]);
                  helper(candidates, target - candidates[i], i + 1, subset, ans);
                  subset.pop_back();
              }
          }
      
          vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
              sort(candidates.begin(), candidates.end());
              vector<vector<int>> ans;
              vector<int> subset;
              helper(candidates, target, 0, subset, ans);
              return ans;
          }
      };
      
    
    int main() {
      Solution obj;
      int n, target;
  
      cout << "Enter number of elements: ";
      cin >> n;
  
      vector<int> candidates(n);
      cout << "Enter elements: ";
      for (int i = 0; i < n; i++)
          cin >> candidates[i];
  
      cout << "Enter target sum: ";
      cin >> target;
  
      vector<vector<int>> result = obj.combinationSum2(candidates, target);
  
      cout << "\nUnique Combinations that sum to " << target << ":\n";
      for (auto& comb : result) {
          cout << "[ ";
          for (auto& num : comb)
              cout << num << " ";
          cout << "]\n";
      }
  
      return 0;
  }