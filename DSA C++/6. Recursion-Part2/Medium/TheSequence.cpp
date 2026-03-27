#include<iostream>
using namespace std;
int theSequence(int n){
  if(n==0){
    return 1;
  }
  return n + n * theSequence(n-1);
}
int main(){
 cout << theSequence(2)<< endl;
  return 0;
}