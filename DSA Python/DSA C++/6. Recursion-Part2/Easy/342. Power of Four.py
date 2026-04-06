# 342. Power of Four.py - Python skeleton converted from C++

# Original C++ code:
# // Given an integer n, return true if it is a power of four. Otherwise, return false.
# 
# // An integer n is a power of four, if there exists an integer x such that n == 4x.
# 
#  
# 
# // Example 1:
# 
# // Input: n = 16
# // Output: true
# 
# // Example 2:
# 
# // Input: n = 5
# // Output: false
# 
# // Example 3:
# 
# // Input: n = 1
# // Output: true
# 
#  
# 
# // Constraints:
# 
# //     -231 <= n <= 231 - 1
# 
# 
# class Solution {
#   public:
#       bool isPowerOfFour(int n) {
#          if(n<=0){
#               return false;
#           }
#           while(n%4==0){
#               n/=4;
#           }
#           return n==1; 
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
