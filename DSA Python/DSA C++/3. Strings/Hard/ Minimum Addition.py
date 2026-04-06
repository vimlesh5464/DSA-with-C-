#  Minimum Addition.py - Python skeleton converted from C++

# Original C++ code:
# // Bob gave Alice a string str that represents the pattern of trees in a garden, where str[i] denotes the pattern of an ith tree. Bob wants the pattern of trees to be the same if seen in the forward and backward directions. By mistake, the last pattern of the trees changed to the ‘c’ pattern. 
# 
# // To make Bob happy, Alice planted some trees at the start of the garden so that he could make the final pattern the same from both forward and backward directions. Your task is to find the minimum number of plants to be planted in the garden to make Bob happy. 
# 
# // Note: str contains only lowercase english alphabets.
# 
# // Input Format
# 
# // The first and only line contains a single string str.
# 
# // Output Format
# 
# // Print a single integer that represents the minimum number of plants to be planted at the starting of the garden to make Bob happy.
# 
# // Constraints
# 
# // 1 <= |str| <= 10^5
# 
# // Sample Testcase 0
# 
# // Testcase Input
# // caan
# // Testcase Output
# // 0
# // Explanation
# 
# // As the last pattern of the tree changed to ‘c,’ the string will become “caac” which is already the same pattern from both forward and backward directions.
# // Sample Testcase 1
# 
# // Testcase Input
# // abd
# // Testcase Output
# // 2
# // Explanation
# 
# // After changing the last pattern, the string will become “abc”, and we can plant a tree with pattern "b" and “c” at starting. 
# 
# // The new string will be "cbabc"
# 
# // The string will become the same from both forward and backward direction after planting two trees. Hence the answer is 2.
# 
# #include <iostream>
# #include <vector>
# #include <algorithm>
# using namespace std;
# 
# bool isPalindrome(const string &s, int i, int j) {
#   while (i < j) {
#       if (s[i] != s[j]) return false;
#       i++;
#       j--;
#   }
#   return true;
# }
# 
# int minimum_addition(string str) {
#   int n = str.size();
# 
#   // Step 1: modify last character ONCE
#   str[n - 1] = 'c';
# 
#   // Step 2: find minimum additions
#   for (int i = 0; i < n; i++) {
#       if (isPalindrome(str, i, n - 1)) {
#           return i;
#       }
#   }
# 
#   return n;
# }
# 
# // Build LPS array
# vector<int> computeLPS(string s) {
#     int n = s.size();
#     vector<int> lps(n, 0);
# 
#     for (int i = 1, len = 0; i < n; ) {
#         if (s[i] == s[len]) {
#             lps[i++] = ++len;
#         } else {
#             if (len != 0) {
#                 len = lps[len - 1];
#             } else {
#                 lps[i++] = 0;
#             }
#         }
#     }
#     return lps;
# }
# 
# int minimum_addition(string str) {
#     int n = str.size();
# 
#     // Step 1: fix last character
#     str[n - 1] = 'c';
# 
#     // Step 2: reverse string
#     string rev = str;
#     reverse(rev.begin(), rev.end());
# 
#     // Step 3: combine
#     string temp = str + "#" + rev;
# 
#     // Step 4: LPS
#     vector<int> lps = computeLPS(temp);
# 
#     // Step 5: answer
#     return n - lps.back();
# }
# 
# int main() {
#     string input;
#     cin >> input;
#     cout << minimum_addition(input);
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
