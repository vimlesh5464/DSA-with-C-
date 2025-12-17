#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int maxlen = 0;
          for(int i = 0; i < nums.size(); i++){
              int zero=0;
              for(int j =i; j < nums.size(); j++){
                  if(nums[j]==0){
                      zero++;
                  }
                  if(zero<=k){
                      int len = j-i+1;
                      maxlen = max(maxlen,len);
                  }else{
                      break;
                  }
              }
          }
          return maxlen;
      }
  };
class Solution {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int maxlen = 0, l=0, r=0, zero=0;
          while(r<nums.size()){
              if(nums[r]==0){
                  zero++;
              }
              while(zero>k){
                  if(nums[l]==0){
                      zero--;
                      
                  }
                  l++;
              }
              if(zero<=k){
                  int len = r-l+1;
                  maxlen=max(maxlen,len);
              }
              r++;
          }
          return maxlen;
      }
  };
