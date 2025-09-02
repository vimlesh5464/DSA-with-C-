#include<iostream>
using namespace std;
void subset(string s, string ans){
  if(s.size()==0){
    cout<< ans << endl;
    return;
  }
  char ch =s[0];
  subset(s.substr(1, s.size()-1), ans+ch);
  subset(s.substr(1, s.size()-1), ans);
}
int main(){
  string s = "abc";
  string ans = " ";
  
   subset(s, ans);
  return 0;
}