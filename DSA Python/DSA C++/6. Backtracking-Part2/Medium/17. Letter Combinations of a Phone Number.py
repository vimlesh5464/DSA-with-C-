# 17. Letter Combinations of a Phone Number.py - Python skeleton converted from C++

# Original C++ code:
# // Given a string containing digits from 2-9 inclusive, return all possible 
# //letter combinations that the number could represent. Return the answer in 
# //any order.
# 
# // A mapping of digits to letters (just like on the telephone buttons) is 
# //given below. Note that 1 does not map to any letters.
# 
#  
# 
# // Example 1:
# // Input: digits = "23"
# // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
# 
# // Example 2:
# // Input: digits = "2"
# // Output: ["a","b","c"]
# 
#  
# 
# // Constraints:
# //     1 <= digits.length <= 4
# //     digits[i] is a digit in the range ['2', '9'].
# 
# #include<iostream>
# #include<vector>
# #include<string>
# using namespace std;
# class Solution {
#   public:
#   void bracktrack(string digits,vector<string>& ans, int index,string current,vector<string>& maps){
#       if(index==digits.size()){
#           if(!current.empty()){
#               ans.push_back(current);
#           }
#           return;
#       }
#       string letters = maps[digits[index]-'0'];
#       for(char ch: letters){
#           current.push_back(ch);
#           bracktrack(digits,ans,index+1,current,maps);
#           current.pop_back();   
#       }
#   }
#       vector<string> letterCombinations(string digits) {
#           vector<string> ans;
#           if(digits.empty()){
#               return ans;
#           }
#           vector<string> maps={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
#           bracktrack(digits,ans,0,"",maps);
#           for(int i = 0; i < ans.size(); i++){
#             cout<<ans[i]<<endl;
#           }
#           return ans;
#       }
#   };
#   int main() {
#     Solution obj;
#     string digits;
# 
#     cout << "Enter digits (2-9): ";
#     cin >> digits;
# 
#     obj.letterCombinations(digits);
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
