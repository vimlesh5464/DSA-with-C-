#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
  public:
      int singleNumber(vector<int>& nums) {
       unordered_map<int,int> freq;
          for(int num : nums)
              freq[num]++;
              for (pair<const int, int> &p : freq) {
                if (p.second == 1)
                    return p.first;
            }    
          // for(auto &p : freq)
          //     if(p.second == 1) return p.first;
          return -1;
      }
  };

  class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int result = 0;
            
            for(int num : nums) {
                result ^= num;
            }
            
            return result;
        }
    };