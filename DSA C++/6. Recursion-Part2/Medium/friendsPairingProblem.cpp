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