# 868. Binary Gap.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# using namespace std;
# #include<vector>
# class Solution {
#   public:
#       int binaryGap(int n) {
#           int lastPos = -1;
#           int maxDist = 0;
#           int pos = 0;
#   
#           while(n > 0) {
#               if(n & 1) {  // if current bit is 1
#                   if(lastPos != -1) {
#                       maxDist = max(maxDist, pos - lastPos);
#                   }
#                   lastPos = pos;
#               }
#               n >>= 1;  // right shift
#               pos++;
#           }
#   
#           return maxDist;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
