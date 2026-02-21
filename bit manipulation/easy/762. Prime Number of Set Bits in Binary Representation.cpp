#include<iostream>
using namespace std;
#include<vector>
#include<string>
class Solution {
  public:
   bool isPrime(int n){
          if(n < 2) return false;
          for(int i = 2; i*i <= n; i++){
              if(n % i == 0) return false;
          }
          return true;
      }
      int countPrimeSetBits(int left, int right) {
          vector<string>ans;
          for(int i = left; i<=right; i++){
              string s="";
              int num = i;
              while(num!=0){
                  if(num%2==0){
                      s += to_string(0);
                  }else{
                      s += to_string(1);
                  }
                  num=num/2;
              }
              ans.push_back(s);
          }
          int one = 0;
          for(int i=0; i< ans.size(); i++){
               int count = 0;
              for(int j =0; j< ans[i].size(); j++){
                  if(ans[i][j]=='1'){
                      count++;
                  }
                  
              }
               if(isPrime(count)){   // ← yaha hona chahiye
          one++;
      }
          }
          return one;
      }
  };

  class Solution {
    public:
        bool isPrime(int n){
            if(n < 2) return false;
            for(int i = 2; i*i <= n; i++){
                if(n % i == 0) return false;
            }
            return true;
        }
    
        int countPrimeSetBits(int left, int right) {
            int ans = 0;
    
            for(int i = left; i <= right; i++){
                int setBits = __builtin_popcount(i);  // counts number of 1s
    
                if(isPrime(setBits)){
                    ans++;
                }
            }
    
            return ans;
        }
    };