#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
      string longestCommonPrefix(vector<string>& strs) {
          if(strs.empty()){
              return " ";
          }
         int n = strs.size();
         string str = strs[0];
         for(int i = 1; i < n; i++){
          while(strs[i].find(str)!=0){
              str=str.substr(0, str.size() - 1);
          }
         }
         return str;
      }
  };