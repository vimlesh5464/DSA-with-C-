#include<iostream>
#include<vector>
#include<string>
using namespace std;
void helper(string &digit,int i, vector<string>&ans, vector<string> &map,string &s){
  if(i==digit.size()){
    ans.push_back(s);
    return;
  }

  string sr = map[digit[i]-'0'];
  for(char c : sr){
    s += c;
    helper(digit,i+1,ans,map,s);
    s.pop_back();
  }
}
int main(){
  string digit = "23";
  vector<string> map = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  vector<string>ans;
  string s= "";
  helper(digit,0,ans,map,s);

  for(int i = 0; i< ans.size(); i++){
    cout<< ans[i] <<  " ";
  }
  return 0;
}