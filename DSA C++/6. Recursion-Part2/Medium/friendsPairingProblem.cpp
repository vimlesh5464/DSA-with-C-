// Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

// Examples :

// Input: n = 3
// Output: 4
// Explanation:
// {1}, {2}, {3} : All single
// {1}, {2,3} : 2 and 3 paired but 1 is single.
// {1,2}, {3} : 1 and 2 are paired but 3 is single.
// {1,3}, {2} : 1 and 3 are paired but 2 is single.
// Note that {1,2} and {2,1} are considered same.

// Input: n = 2
// Output: 2
// Explanation:
// {1} , {2} : All single.
// {1,2} : 1 and 2 are paired.

// Input: n = 1
// Output: 1

// Constraints:
// 1 ≤ n ≤ 18
#include<iostream>
using namespace std;
// friend Pairing Problem
int friendPairingProblem(int n){
  if(n==1 || n==2){
    return n;
  }
  return friendPairingProblem(n-1)+(n-1)*friendPairingProblem(n-2);
}
int main(){
  cout << friendPairingProblem(4);
  return 0;
}