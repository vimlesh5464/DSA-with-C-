#include<iostream>
using namespace std;
//Tiling Problem 3*n 
int tilingProblem(int n){
  if(n==1 || n==0 || n==2){
    return 1;
  }
  //vertical choice
  int a = tilingProblem(n-1);
  //horizontal
  int b = tilingProblem(n-3);
  return a+b;
}

//2*n
    // int numberOfWays(int n) {
    //     // code here
    //     if(n==0|n==1){
    //         return 1;
    //     }
    //     vector<int> dp(n);
    //     dp[0]=dp[1]=1;
    //     for(int i =2; i <= n; i++){
    //         dp[i] = dp[n-1]+dp[n-2];
    //     }
       
    //     return dp[n];
    // }

int main(){
  cout<<tilingProblem(3);
return 0;
}