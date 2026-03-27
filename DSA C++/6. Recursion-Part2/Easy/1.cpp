#include<iostream>
using namespace std;
// print N to 1 number
void recursionNto1(int n){
  if(n==0){
    return;
  }
  cout<<n<<" ";
  recursionNto1(n-1);
}

// print 1 to N number
void recursion1toN(int n){
  if(n==0){
    return;
  }
  
  recursion1toN(n-1);
  cout<<n<<" ";
}
