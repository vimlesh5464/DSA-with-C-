# 320. Generalized Abbreviation.py - Python skeleton converted from C++

# Original C++ code:
# // You are given a string ‘STR’ consisting of English lowercase letters.
# 
# // Your task is to find out all the generalised abbreviations of ‘STR’ and print an
# //array/list of these abbreviations sorted in increasing order.
# 
# // Note:
# 
# // A string is said to be a generalised abbreviations string of ‘STR’ if we remove
# // a substring of length ‘X’ from ‘STR’ and put the number ‘X’ at the place of the 
# //removed substring.
# 
# // We can not remove two consecutive substrings or we can say generalised 
# //abbreviations will never have two consecutive numbers.
# 
# // For example:
# 
# // If ‘STR’ = “abc”,
# // Sorted generalized abbreviations of ‘STR’ are: [“1b1”, “1bc”, “2c”, “3”, “a1c”, “a2”, “ab1”, “abc”].
# 
# // Input Format:
# 
# // The first line of input contains a single integer T, representing the number of test cases.
# // Then the T test cases follow.
# 
# // The first and the only line of each test case contains a string ‘STR’.
# 
# // Output format:
# 
# // For every test case, print all the generalised abbreviations of ‘STR’ separated by a single space.
# 
# // The output of each test case is printed in a separate line.
# 
# // Note :
# 
# // You don’t have to print anything. It has already been taken care of. Just implement the given function. 
# 
# // Constraints:
# 
# // 1<= T <=10
# // 1<= |STR| <= 20
# 
# // Where |STR| is length of String 'STR'.
# 
# // Time limit: 1 sec
# 
# #include<iostream>
# #include<vector>
# using namespace std;
# 
# void dfs(string &str, int index, string curr, int count, vector<string> &ans) {
# 
#     if (index == str.size()) {
#         if (count > 0) curr += to_string(count);
#         ans.push_back(curr);
#         return;
#     }
# 
#     dfs(str, index + 1, curr, count + 1, ans);
# 
#     if (count > 0) curr += to_string(count);
#     dfs(str, index + 1, curr + str[index], 0, ans);
# }
# 
# vector<string> findAbbr(string &str) {
#     vector<string> ans;
#     dfs(str, 0, "", 0, ans);
# 
#     // ⭐ Important: Sort lexicographically to match expected output:
#     sort(ans.begin(), ans.end());
# 
#     return ans;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
