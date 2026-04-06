# 50. Pow(x, n).py - Python skeleton converted from C++

# Original C++ code:
# // Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
# 
#  
# 
# // Example 1:
# 
# // Input: x = 2.00000, n = 10
# // Output: 1024.00000
# 
# // Example 2:
# 
# // Input: x = 2.10000, n = 3
# // Output: 9.26100
# 
# // Example 3:
# 
# // Input: x = 2.00000, n = -2
# // Output: 0.25000
# // Explanation: 2-2 = 1/22 = 1/4 = 0.25
# 
#  
# 
# // Constraints:
# 
# //     -100.0 < x < 100.0
# //     -231 <= n <= 231-1
# //     n is an integer.
# //     Either x is not zero or n > 0.
# //     -104 <= xn <= 104
# 
#  
# 
# #include<iostream>
# using namespace std;
# class Solution {
#   public:
#       double myPow(double x, int n) {
#           // Convert n to long long to handle INT_MIN safely
#           long long N = n;
#           if (N < 0) {
#               x = 1 / x;
#               N = -N;
#           }
#           return fastPow(x, N);
#       }
#   
#       double fastPow(double x, long long n) {
#           if (n == 0) return 1.0;
#   
#           double half = fastPow(x, n / 2);
#           if (n % 2 == 0)
#               return half * half;
#           else
#               return half * half * x;
#       }
#   };
#   
#   class Solution {
#     public:
#         double myPow(double x, int n) {
#             long long N = n;
#         if (N < 0) {
#             x = 1 / x;
#             N = -N;
#         }
#     
#         double result = 1.0;
#         while (N > 0) {
#             if (N % 2 == 1) {
#                 result *= x;
#             }
#             x *= x;
#             N /= 2;
#         }
#     
#         return result;
#         }
#     };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
