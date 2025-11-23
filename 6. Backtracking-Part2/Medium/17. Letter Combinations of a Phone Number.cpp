#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
  public:
  void bracktrack(string digits,vector<string>& ans, int index,string current,vector<string>& maps){
      if(index==digits.size()){
          if(!current.empty()){
              ans.push_back(current);
          }
          return;
      }
      string letters = maps[digits[index]-'0'];
      for(char ch: letters){
          current.push_back(ch);
          bracktrack(digits,ans,index+1,current,maps);
          current.pop_back();   
      }
  }
      vector<string> letterCombinations(string digits) {
          vector<string> ans;
          if(digits.empty()){
              return ans;
          }
          vector<string> maps={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
          bracktrack(digits,ans,0,"",maps);
          for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<endl;
          }
          return ans;
      }
  };
  int main() {
    Solution obj;
    string digits;

    cout << "Enter digits (2-9): ";
    cin >> digits;

    obj.letterCombinations(digits);

    return 0;
}