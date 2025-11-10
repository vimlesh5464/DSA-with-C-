#include<iostream>
#include<vector>
using namespace std;
int combi(vector<int>& nums,int i,vector<int>&subset,vector<vector<int>>&ans,int target){
  
  if(i==nums.size()){
    if(target==0){
      ans.push_back(subset);
      return 1;
    }
    
  }
if(i==nums.size() || target<0){
  return 0;
}

subset.push_back(nums[i]);
int include = combi(nums,i,subset,ans,target-nums[i]);
subset.pop_back();

int exclude=combi(nums,i+1,subset,ans,target);
return include+exclude;
}
int main(){
  vector<int> subset;
  int target = 2;
  vector<int> nums={1,2,3};
  vector<vector<int>> ans;
  int count = combi(nums,0,subset,ans,target);
  cout<< "count: "<<count<<endl;
  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }
  return 0;
}