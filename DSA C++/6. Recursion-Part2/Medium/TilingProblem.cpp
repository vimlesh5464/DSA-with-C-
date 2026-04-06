#include<iostream>
using namespace std;
int tilingProblem(int n){
  if(n == 0) return 1;
  if(n < 0) return 0;

  // vertical placement
  int a = tilingProblem(n - 1);

  // horizontal placement (3 tiles)
  int b = tilingProblem(n - 3);

  return a + b;
}
int solve(int n, vector<int> &dp) {
  if(n == 0) return 1;
  if(n < 0) return 0;

  if(dp[n] != -1) return dp[n];

  return dp[n] = solve(n-1, dp) + solve(n-3, dp);
}

int tilingProblem(int n){
  vector<int> dp(n+1, -1);
  return solve(n, dp);
}

//2*n
int solve(int n, vector<int> &dp){
  if(n == 0 || n == 1) return 1;

  if(dp[n] != -1) return dp[n];

  return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int tilingProblem(int n){
  vector<int> dp(n+1, -1);
  return solve(n, dp);
}

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