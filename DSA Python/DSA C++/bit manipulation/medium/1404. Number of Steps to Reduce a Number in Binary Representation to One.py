# 1404. Number of Steps to Reduce a Number in Binary Representation to One.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# #include<string>
# using namespace std;
# 
# class Solution {
#   public:
#       int numSteps(string s) {
#           int steps = 0;
#           int carry = 0;
#           
#           // Traverse from right to left (except first bit)
#           for (int i = s.length() - 1; i > 0; i--) {
#               if ((s[i] - '0' + carry) % 2 == 0) {
#                   // Even
#                   steps += 1;
#               } else {
#                   // Odd
#                   steps += 2;
#                   carry = 1;
#               }
#           }
#           
#           return steps + carry;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
