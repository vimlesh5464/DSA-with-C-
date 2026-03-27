#include<iostream>
using namespace std;
//palidrome checku  using recursion
bool palidrome(string &s, int i, int j){
  int n = s.length();
  
  if(i>=j){
    return true;
  }
  return s[i]==s[j] && palidrome(s, i+1, j-1);
}

int main(){
  string s = "madama";
  int n = s.length();
  cout<< palidrome(s, 0, n-1)<<endl;
  return 0;
}