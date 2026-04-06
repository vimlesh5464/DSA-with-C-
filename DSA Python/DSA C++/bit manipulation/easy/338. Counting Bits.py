# 338. Counting Bits.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# using namespace std;
# #include<vector>
# #include<string>
# class Solution {
#   public:
#   // Count set bits in binary string
#   int countSetBits(string binary) {
#       int count = 0;
#   
#       for(char bit : binary) {
#           if(bit == '1') count++;
#       }
#   
#       return count;
#   }
#   
#   // Convert decimal to binary string
#   string decimalToBinary(int n) {
#       if (n == 0) return "0";
#   
#       string binary = "";
#   
#       while (n > 0) {
#           binary = to_string(n % 2) + binary;
#           n = n / 2;
#       }
#   
#       return binary; // ✅ FIXED
#   }
#       vector<int> countBits(int n) {
#          int count = 0;
#          vector<int> ans;
#       for(int i = 0; i <= n; i++) {
#           string binary = decimalToBinary(i);  // convert
#           count = countSetBits(binary); 
#           ans.push_back(count);    // count 1s
#       }
#   
#       return ans; 
#       }
#   };
# 
#   vector<int> countBits(int n) {
#     vector<int> ans(n + 1);
# 
#     for(int i = 1; i <= n; i++) {
#         ans[i] = ans[i / 2] + (i % 2);
#     }
# 
#     return ans;
# }
# 
# 
# 
# class Solution {
#   public:
#     int countSetBits(int n) {
#         // code here
#         if (n == 0) return 0;
# 
#         int x = log2(n);  // largest power of 2
#         
#         int bitsTill2x = x * (1 << (x - 1));   // bits from 1 to 2^x - 1
#         int msb2xToN = n - (1 << x) + 1;       // MSB bits from 2^x to n
#         int rest = n - (1 << x);               // remaining numbers
# 
#         return bitsTill2x + msb2xToN + countSetBits(rest);
#     }
# };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
