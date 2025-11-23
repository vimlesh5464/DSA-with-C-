#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
  public:
  void helper(vector<int>& candidates,int target,int i,vector<int>&subset,set<vector<int>>&ans){
      if(i==candidates.size()){
          if(target==0){
              ans.insert(subset);
          }
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