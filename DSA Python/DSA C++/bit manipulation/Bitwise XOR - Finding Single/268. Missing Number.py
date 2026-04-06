# 268. Missing Number.py - Python skeleton converted from C++

# Original C++ code:
# 
# #include<iostream>
# using namespace std;
# #include<vector>
# class Solution {
#   public:
#       int missingNumber(vector<int>& nums) {
#           int xor1 = 0, xor2 = 0;
#           int n = nums.size();
#           for(int i = 0; i < n; i++){
#               xor2 = xor2 ^ nums[i];
#               xor1 = xor1 ^ (i+1);
#           }
#          
#           return xor1 ^ xor2;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
