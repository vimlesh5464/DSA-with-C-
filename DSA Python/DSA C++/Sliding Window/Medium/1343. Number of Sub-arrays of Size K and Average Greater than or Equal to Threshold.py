# 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include <vector>
# #include<unordered_map>
# using namespace std;
# 
# // O(n * k)
# class Solution {
#   public:
#       int numOfSubarrays(vector<int>& arr, int k, int threshold) {
#           int n = arr.size();
#           int count = 0;
#   
#           for (int i = 0; i <= n - k; i++) {
#               long long sum = 0;
#   
#               // calculate sum of subarray [i ... i+k-1]
#               for (int j = i; j < i + k; j++) {
#                   sum += arr[j];
#               }
#   
#               double avg = (double)sum / k;
#   
#               if (avg >= threshold)
#                   count++;
#           }
#   
#           return count;
#       }
#   };
#   
# class Solution {
#   public:
#       int numOfSubarrays(vector<int>& arr, int k, int threshold) {
#           int n = arr.size();
#           int count = 0;
#           long long windowSum = 0;
#           long long target = (long long)threshold * k;
#   
#           // First window
#           for (int i = 0; i < k; i++) {
#               windowSum += arr[i];
#           }
#   
#           if (windowSum >= target) count++;
#   
#           // Slide window
#           for (int i = k; i < n; i++) {
#               windowSum += arr[i];
#               windowSum -= arr[i - k];
#   
#               if (windowSum >= target)
#                   count++;
#           }
#   
#           return count;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
