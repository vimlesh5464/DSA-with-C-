# 136. Single Number.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# using namespace std;
# #include<vector>
# #include<unordered_map>
# class Solution {
#   public:
#       int singleNumber(vector<int>& nums) {
#        unordered_map<int,int> freq;
#           for(int num : nums)
#               freq[num]++;
#               for (pair<const int, int> &p : freq) {
#                 if (p.second == 1)
#                     return p.first;
#             }    
#           // for(auto &p : freq)
#           //     if(p.second == 1) return p.first;
#           return -1;
#       }
#   };
# 
#   class Solution {
#     public:
#         int singleNumber(vector<int>& nums) {
#             int result = 0;
#             
#             for(int num : nums) {
#                 result ^= num;
#             }
#             
#             return result;
#         }
#     };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
