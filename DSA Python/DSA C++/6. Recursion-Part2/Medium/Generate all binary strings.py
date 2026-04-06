# Generate all binary strings.py - Python skeleton converted from C++

# Original C++ code:
# // Given an integer n. You need to generate all the binary strings of n characters representing bits.
# 
# // Note: Return the strings in  ascending order.
# 
# // Examples:
# 
# // Input: n = 2
# // Output: [00, 01, 10, 11]
# // Explanation: As each position can be either 0 or 1, the total possible combinations are 4.
# 
# // Input: n = 3
# // Output: [000, 001, 010, 011, 100, 101, 110, 111]
# // Explanation: As each position can be either 0 or 1, the total possible combinations are 8.
# 
# // Constraints:
# // 1 ≤ n ≤ 20
# #include<iostream>
# using namespace std;
# 
# class Solution {
#   public:
#       void binaryString(int n, string ans, vector<string>& res) {
#           if (n == 0) {
#               res.push_back(ans);
#               return;
#           }
#           // Put '0' at current position
#           binaryString(n - 1, ans + '0', res);
#           // Put '1' at current position
#           binaryString(n - 1, ans + '1', res);
#       }
#   
#       vector<string> binstr(int n) {
#           vector<string> res;
#           binaryString(n, "", res);
#           return res;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
