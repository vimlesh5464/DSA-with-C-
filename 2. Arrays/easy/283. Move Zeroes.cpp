#include <iostream>
#include<vector>
using namespace std;
// Time: O(n)

// Space: O(n) (extra list ans)
class Solution {
  public:
      void moveZeroes(vector<int>& nums) {
          int n = nums.size();
          vector<int> ans;
          for(int i = 0; i < n; i++){
              if(nums[i]!=0){
                  ans.push_back(nums[i]);
              }
          }
          int n2 = ans.size();
          for(int i = 0; i < n2; i++){
              nums[i] = ans[i];
          }
          for(int i = n2; i < n; i++){
              nums[i] = 0;
          }
      }
  };

//   Time: O(n)

// Space: O(1) 
  class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int k = 0;  // position for next non-zero element
    
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    nums[k] = nums[i];
                    k++;
                }
            }
    
            // fill remaining positions with 0
            for (int i = k; i < nums.size(); i++) {
                nums[i] = 0;
            }
        }
    };
    