// Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of the given array must be used to form the two numbers.

// Any combination of digits may be used to form the two numbers to be summed.  Leading zeroes are permitted.

// If forming two numbers is impossible (i.e. when n==0) then the "sum" is the value of the only number that can be formed.


 

 

// Example 1:

// Input:
// N = 6
// arr[] = {6, 8, 4, 5, 2, 3}
// Output:
// 604
// Explanation:
// The minimum sum is formed by numbers 
// 358 and 246

 

// Example 2:

// Input:
// N = 5
// arr[] = {5, 3, 0, 7, 4}
// Output:
// 82
// Explanation:
// The minimum sum is formed by numbers 
// 35 and 047



// Your Task:
// You don't have to print anything, printing is done by the driver code itself. Your task is to complete the function minSum() which takes the array A[] and its size N as inputs and returns the required sum.

// Expected Time Complexity: O(N. log(N))
// Expected Auxiliary Space: O(N)
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Solution {
  public:
      
      // Helper: add two strings
      string addStrings(string a, string b) {
          string res = "";
          int i = a.size() - 1, j = b.size() - 1, carry = 0;
  
          while (i >= 0 || j >= 0 || carry) {
              int sum = carry;
  
              if (i >= 0) sum += a[i--] - '0';
              if (j >= 0) sum += b[j--] - '0';
  
              res.push_back((sum % 10) + '0');
              carry = sum / 10;
          }
  
          reverse(res.begin(), res.end());
          return res;
      }
  
      long long int minSum(int arr[], int n) {
          
          // Step 1: min heap
          priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
  
          string num1 = "", num2 = "";
  
          // Step 2: build numbers alternately
          while (!pq.empty()) {
              num1 += to_string(pq.top());
              pq.pop();
  
              if (!pq.empty()) {
                  num2 += to_string(pq.top());
                  pq.pop();
              }
          }
  
          // Step 3: add as strings
          string result = addStrings(num1, num2);
  
          // Step 4: convert (safe if within range)
          return stoll(result);
      }
  };
int minSum(vector<int> &arr) {
    
    // Create min heap
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    string num1, num2;

    while (!pq.empty()) {
        num1 += to_string(pq.top()); pq.pop();
        if (!pq.empty()) {
            num2 += to_string(pq.top()); pq.pop();
        }
    }
    return stoi(num1) + stoi(num2);
}

int main() {
    vector<int> arr = {5, 3, 0, 7, 4};
    cout << minSum(arr);
}