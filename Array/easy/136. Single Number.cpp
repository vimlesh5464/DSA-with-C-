// Approaches
// 1. Using Hash Map (Count Frequency)
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums)
            freq[num]++;
        for(auto &p : freq)
            if(p.second == 1) return p.first;
        return -1;
    }
};

//2. Using XOR (Optimal) ✅
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
  public:
      int singleNumber(vector<int>& nums) {
          int result = 0;
          for(int num : nums)
              result ^= num; // XOR all elements
          return result;
      }
  };
  

int main() {
    Solution s;
    vector<int> nums = {4,1,2,1,2};
    cout << "Single Number: " << s.singleNumber(nums) << endl;
    return 0;
}
