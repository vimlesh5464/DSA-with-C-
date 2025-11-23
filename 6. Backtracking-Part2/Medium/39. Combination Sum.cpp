#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  void helper(vector<int>&candidates,int target,vector<int>&subset,vector<vector<int>>&ans, int i){
      if(i==candidates.size()){
          if(target==0){
              ans.push_back(subset);
          }
          return;
      }
      if(i==candidates.size() || target<0){
           return;   
      }
  
      subset.push_back(candidates[i]);
      helper(candidates,target-candidates[i],subset,ans,i);
      subset.pop_back();
      helper(candidates,target,subset,ans,i+1);
  }
      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>>ans;
          vector<int> subset;
          helper(candidates,target,subset,ans,0);
          for(int i = 0; i < ans.size(); i++){
              for(int j=0; j < ans[i].size(); j++){
                  cout<<ans[i][j];
              }
              cout<<endl;
          }
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

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "\nUnique Combinations that sum to " << target << ":\n";
    for (auto& comb : result) {
        cout << "[ ";
        for (auto& num : comb)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}