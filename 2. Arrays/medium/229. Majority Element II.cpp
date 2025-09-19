
#include <iostream>
#include<vector>
using namespace std;

//Time Complexity: O(N2)
//Space Complexity: O(N2)
class Solution {
  public:
      vector<int> majorityElement(vector<int>& nums) {
          int n = nums.size();
          vector<int> result;
          for(int i = 0; i < n; i++){
              int cnt = 0;
              for(int j = 0; j < n; j++){
                  if(nums[j] == nums[i]){
                      cnt++;
                  }
              }
              // avoid duplicates
              if(cnt > n / 3 && find(result.begin(), result.end(), nums[i]) == result.end()){
                  result.push_back(nums[i]);
              }
          }
          return result; // ✅ always return result (even if empty)
      }
  };
  
//Time Complexity: O(N) + O(N)
//Space Complexity: O(1) 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find potential candidates
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        // Step 3: Collect results
        vector<int> result;
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> ans = sol.majorityElement(nums);

    cout << "Majority elements (> n/3): ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
