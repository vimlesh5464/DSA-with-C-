#include<iostream>
#include<vector>
#include<map>
using namespace std;
void permu(vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,vector<int>&freq){
  int n = arr.size();
  if(ds.size()==n){
    ans.push_back(ds);
    return;
  }

  for(int i = 0; i < n; i++){
    if(!freq[i]){
      ds.push_back(arr[i]);
      freq[i]=1;
      permu(arr,ans,ds,freq);
      ds.pop_back();
      freq[i]=0;
    }
  }
}
int main(){
  vector<int> arr={1,2,3};
  vector<vector<int>>ans;
  vector<int> ds;
  vector<int> freq(arr.size(), 0);
  permu(arr, ans, ds, freq);
  for(int i = 0; i < ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout<< ans[i][j];
    }
    cout<< endl;
  }
  return 0;
}
class Solution {
  public:
  void get(vector<int>& nums, int ind, vector<vector<int>> &result){
      if(ind==nums.size()){
          result.push_back({nums});
          return;
      }
      for(int i = ind; i < nums.size(); i++){
          swap(nums[ind], nums[i]);
          get(nums, ind+1, result);
          swap(nums[ind], nums[i]);
      }
  }
      vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> result;
          get(nums, 0, result);
          return result;
      }
  };