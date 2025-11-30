#include <iostream>

#include<vector>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
  vector<int> ans;
  int n = nums.size();
  
  for(int i = 0; i < n; i++){
      
      ans.push_back(nums[i]*nums[i]);
  }
  sort(ans.begin(),ans.end());
  
  return ans;
}
int main() {
  
  vector<int> nums = {-4,-1,0,3,10};
  vector<int> ans=sortedSquares(nums);
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
}
cout << endl;
  return 0;
}
