#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int threeSumClosest(vector<int>& nums, int target) {
          sort(nums.begin(),nums.end());
          int closest = nums[0] + nums[1] + nums[2];
  
          for(int i = 0; i < nums.size(); i++){
              int j = i+1, k = nums.size()-1;
              while(j < k){
                  int sum = nums[i]+nums[j]+nums[k];
                  if(abs(target - sum) < abs(target - closest)){
                      closest=sum;
                  }else if(sum<target){
                      j++;
                  }else{
                      k--;
                  }
              }
          }
          return closest;
      }
  };