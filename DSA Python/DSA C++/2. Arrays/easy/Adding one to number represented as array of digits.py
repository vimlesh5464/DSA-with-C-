# Adding one to number represented as array of digits.py - Python skeleton converted from C++

# Original C++ code:
# // Given a non-negative number represented as an array of digits. The task is to add 1 to the number (increment the number represented by the digits by 1). The digits are stored such that the most significant digit is the first element of the array.
# 
# // Examples :
# 
# //     Input : [1, 2, 4]
# //     Output : 125
# //     Explanation: 124 + 1 = 125 
# 
# //     Input : [9, 9, 9]
# //     Output: 1000
# //     Explanation: 999 + 1 = 1000 
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# //[Approach - 1] - Using Carry - O(n) Time and O(1) Space
# vector<int> addOne(vector<int> &arr) {
# 
#   
#     int carry = 1;
# 
#     for(int i = arr.size() - 1; i >= 0; i--) {
#         int sum = arr[i] + carry;
#         arr[i] = sum % 10;
#         carry = sum / 10;
#     }
# 
#     if(carry) {
#         arr.insert(arr.begin(), carry);
#     }
# 
#     return arr;
# }
# 
# //[Approach - 2] - O(n) Time and O(1) Space
# vector<int> addOne(vector<int> &arr) {
# 
#   int n = arr.size();
#         
#         // Start from last digit
#         for (int i = n - 1; i >= 0; i--) {
#             if (arr[i] < 9) {
#                 arr[i]++;     // no carry, done
#                 return arr;
#             }
#             arr[i] = 0;       // carry forward
#         }
# 
#         // If we reach here, all digits were 9
#         arr.insert(arr.begin(), 1);
#         return arr;
# }
# 
# 
# int main() {
#     vector<int> arr = {9, 9, 9};
#     vector<int> res = addOne(arr);
#     for(auto i:res) {
#         cout << i;
#     }
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
