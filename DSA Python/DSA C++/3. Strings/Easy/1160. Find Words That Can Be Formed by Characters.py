# 1160. Find Words That Can Be Formed by Characters.py - Python skeleton converted from C++

# Original C++ code:
# // Vikas needs help solving a puzzle where he must find which words can be formed using the characters from a given string.
# // You are given an array of strings W with N elements and a string C. A word is considered "good" if it can be formed using the characters from C, with each character in C being used at most once.
# // Your task is to calculate and return the sum of the lengths of all the "good" strings in the array W.
# 
# // Input Format
# 
# // The first line contains an integer N, representing the length of the array W.
# // The next N line takes a single string representing the element of array W.
# // The last line contains the single string C, representing the character string.
# 
# // Output Format
# 
# // Print the sum of the lengths of all the good strings in the words.
# 
# // Constraints
# 
# // 1 <= N <= 10^3
# // 1 <= W[i].length, C.length <= 10^2
# 
# 
# // Sample Testcase 0
# 
# // Testcase Input
# // 5
# // abc
# // bce
# // mcb
# // nab
# // omn
# // zklac
# // Testcase Output
# // 0
# // Explanation
# 
# // There are  no string that can be formed using the characters in the string "zklac".
# // Sample Testcase 1
# 
# // Testcase Input
# // 10
# // cmkkm
# // uqguo
# // ilgpk
# // ovjad
# // cyzpx
# // tptjk
# // uhyta
# // qarhb
# // sqaed
# // fdfdf
# // ovjadqguoqarhb
# // Testcase Output
# // 10
# // Explanation
# 
# // WIth the characters in "ovjadqguoqarhb" we can form the strings:
# 
# 
# // 1) "ovjad" of length 5 as all character of string appear in string C
# // 2) "qarhb" of length 5 as all character of string appear in string C
# 
# // Therefore, the sum of total length is 5 + 5 = 10
# #include <iostream>
# #include <vector>
# #include <string>
# using namespace std;
# 
# 
# int count_characters(const vector<string>& W, const string& C) {
#     // Step 1: Count frequency of C
#     vector<int> countC(26, 0);
#     for (char ch : C) {
#         countC[ch - 'a']++;
#     }
# 
#     int sum = 0;
# 
#     // Step 2: Check each word
#     for (const string& word : W) {
#         vector<int> countW(26, 0);
#         for (char ch : word) {
#             countW[ch - 'a']++;
#         }
# 
#         bool canForm = true;
#         for (int i = 0; i < 26; i++) {
#             if (countW[i] > countC[i]) {
#                 canForm = false;
#                 break;
#             }
#         }
# 
#         if (canForm) {
#             sum += word.length();
#         }
#     }
# 
#     return sum;
# }
# 
# int main() {
#     int N;
#     cin >> N;
#     vector<string> W(N);
#     for (int i = 0; i < N; i++) {
#         cin >> W[i];
#     }
# 
#     string C;
#     cin >> C;
# 
#     cout << count_characters(W, C) << endl;
# 
#     return 0;
# }
# 
# int main() {
#     int N;
#     cin >> N;
# 
#     vector<string> W(N);
#     for (int i = 0; i < N; i++) {
#         cin >> W[i];
#     }
# 
#     string C;
#     cin >> C;
# 
#     int sum = 0;
# 
#     // Loop through each word
#     for (string word : W) {
#         string tempC = C;  // copy of C to remove used letters
#         bool canForm = true;
# 
#         for (char ch : word) {
#             size_t pos = tempC.find(ch);  // find character in C
#             if (pos != string::npos) {
#                 tempC.erase(pos, 1);  // remove used character
#             } else {
#                 canForm = false;      // character not found → cannot form word
#                 break;
#             }
#         }
# 
#         if (canForm) {
#             sum += word.length();
#         }
#     }
# 
#     cout << sum << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
