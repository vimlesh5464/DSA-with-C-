# Check if an array is subset of another array.py - Python skeleton converted from C++

# Original C++ code:
# // Given two arrays a[] and b[] of size m and n respectively, the task is to determine whether b[] is a subset of a[]. Both arrays are not sorted, and elements are distinct.
# 
# // Examples: 
# 
# //     Input: a[] = [11, 1, 13, 21, 3, 7], b[] = [11, 3, 7, 1] 
# //     Output: true
# 
# //     Input: a[]= [1, 2, 3, 4, 5, 6], b = [1, 2, 4] 
# //     Output: true
# 
# //     Input: a[] = [10, 5, 2, 23, 19], b = [19, 5, 3] 
# //     Output: false
# 
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# bool isSubset(vector<int> &a, vector<int> &b)
# {
# 
#     // Iterate over each element in the second array
#     int m = a.size(), n = b.size();
#     for (int i = 0; i < n; i++)
#     {
#         bool found = false;
# 
#         // Check if the element exists in the first array
#         for (int j = 0; j < m; j++)
#         {
#             if (b[i] == a[j])
#             {
#                 found = true;
#                 a[j] = -1;
#                 break;
#             }
#         }
# 
#         // If any element is not found, return false
#         if (!found)
#             return false;
#     }
# 
#     // If all elements are found, return true
#     return true;
# }
# 
# int main()
# {
#     vector<int> a = {11, 1, 13, 21, 3, 7};
#     vector<int> b = {11, 3, 7, 1};
# 
#     if (isSubset(a, b))
#     {
#         cout << "true" << endl;
#     }
#     else
#     {
#         cout << "false" << endl;
#     }
# 
#     return 0;
# }
# #include <iostream>
# using namespace std;
# 
# bool isSubset(vector<int>& a, vector<int>& b) {
#     sort(a.begin(), a.end());
#     sort(b.begin(), b.end());
# 
#     int i = 0, j = 0;
#     int m = a.size(), n = b.size();
# 
#     while (i < m && j < n) {
#         if (a[i] < b[j]) {
#             // move in a to catch up
#             i++;   
#         }
#         else if (a[i] == b[j]) {
#             i++;
#             // matched one element from b
#             j++;   
#         }
#         else {
#             // a[i] > b[j] → means b[j] is missing
#             return false;
#         }
#     }
#     
#     // all b[] matched
#     return (j == n); 
# }
# 
# int main() {
#     vector<int> a = {11, 1, 13, 21, 3, 7};
#     vector<int> b = {11, 3, 7, 1};
# 
#     if (isSubset(a, b)) cout << "true\n";
#     else cout << "false\n";
# 
#     return 0;
# }
# 
# //[Expected Approach] Using Hashing - O(m + n) Time and O(m) Space
# #include<unordered_set>
# #include <iostream>
# using namespace std;
# 
# bool isSubset( vector<int>& a,  vector<int>& b) {
# 
#     // Create a hash set and insert all elements of a
#     unordered_set<int> hashSet(a.begin(), a.end());
#     
#     // Check each element of b in the hash set
#     for (int num : b) {
#         if (hashSet.find(num) == hashSet.end()) {
#             return false;
#         }
#         hashSet.erase(hashSet.find(num));
#     }
#     
#     // If all elements of b are found in the hash set
#     return true;
# }
# 
# int main() {
#     vector<int> a = {11, 1, 13, 21, 3, 7};
#     vector<int> b = {11, 3, 7, 1};
#     
#     if (isSubset(a, b)) {
#         cout << "true" << endl;
#     } else {
#         cout << "false" << endl;
#     }
#     
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
