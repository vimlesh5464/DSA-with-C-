#include<iostream>
#include<vector>
using namespace std;
int findPeakElement(vector<int>& nums) {
  int low = 0, high = nums.size()-1;
  while(low<high){
      int mid = low + (high-low)/2;
      if(nums[mid]>nums[mid+1]){
          high = mid;
      }else{
          low = mid +1;
      }
  }
  return low;
}

int main(){
  int n;
  cin>> n;
  vector<int> nums;
  for(int i=0; i < n; i++){
    int num;
    cin>>num;
    nums.push_back(num);
  }
  cout<<findPeakElement(nums);
  return 0;
}