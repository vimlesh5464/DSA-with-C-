#include<iostream>
using namespace std;
//print X to power N
int power(int x, int n){//log(n)
  if(n==0){
    return 1;
  }
  int halfpow = power(x, n/2);
  int halfpowSquare = halfpow*halfpow;

  if(n%2!=0){
    return x * halfpowSquare;
  }
  return halfpowSquare;
}
int main(){
  cout<<power(2,10)<<endl;
  return 0;
}