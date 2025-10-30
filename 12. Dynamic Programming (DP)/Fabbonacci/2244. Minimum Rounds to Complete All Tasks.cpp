#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
      int minimumRounds(vector<int>& tasks) {
          unordered_map<int,int> freq;
          for(int t : tasks) freq[t]++;
          
          int rounds = 0;
          for(auto &it : freq){
              int f = it.second;
              if(f == 1) return -1; // impossible
              rounds += (f + 2) / 3; // ceil(f/3)
          }
          
          return rounds;
      }
  };
  
