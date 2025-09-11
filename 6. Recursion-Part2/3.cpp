#include<iostream>
using namespace std;
//Sum of Digits using Recursion
int sumDigit(int n){
  if(n==0){
    return 0;
  }
 
   int a = n%10;
    return a + sumDigit(n/10);
}
int main(){
  cout<< sumDigit(123)<<endl;
  return 0;
}