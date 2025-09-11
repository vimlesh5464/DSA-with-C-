#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//Approach 1: Brute Force (O(n²))
//Time Complexity: O(n²)
//Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }
            if(cnt > n/2)
                return nums[i];
        }
        return -1; // Won't reach if majority element exists
    }
};


//Approach 2: Using Hash Map (O(n))
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
  public:
      int majorityElement(vector<int>& nums) {
          unordered_map<int,int> freq;
          int n = nums.size();
          for(int num : nums) {
              freq[num]++;
              if(freq[num] > n/2) return num;
          }
          return -1;
      }
  };

  //Approach 3: Boyer-Moore Voting Algorithm (Optimal)
//   Time Complexity: O(n)
// Space Complexity: O(1) ✅

  class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0, candidate = 0;
            for(int num : nums) {
                if(count == 0) candidate = num;
                count += (num == candidate) ? 1 : -1;
            }
            return candidate;
        }
    };
int main() {
    Solution s;
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << s.majorityElement(nums) << endl;
    return 0;
}
