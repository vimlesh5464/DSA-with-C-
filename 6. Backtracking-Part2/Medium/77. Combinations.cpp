#include<iostream>
#include<vector>
#include<map>
using namespace std;
void Combinations(int n, int k, int i, vector<vector<int>>&ans,vector<int>& subset){
  if(k==0){
    ans.push_back(subset);
    return;
  }
  for(int index=i; index<=n; index++){
    subset.push_back(index);
    Combinations(n,k-1,index+1,ans,subset);
    subset.pop_back();
  }
}
int main(){
  vector<vector<int>>ans;
  vector<int>subset;
  int n=4;
  int k=2;
  Combinations(n,k,1,ans,subset);
  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }
  return 0;
}
