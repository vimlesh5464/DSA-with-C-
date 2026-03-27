#include<iostream>

using namespace std;
int recursion(int target){
  if(target==0){
    return 1;
  }
  if(target<0){
    return 0;
  }
  int a = recursion(target-1);
  
  int b  =recursion(target-2);
  return a + b;
  
}
int main(){
  int target;
  cin >> target;
  
  cout << recursion(target);
  return 0;
}
