//Approach 1: Brute Force (Shift One by One)
// Time Complexity: O(n*k)
// Space Complexity: O(1)

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void leftRotateBruteForce(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n; // handle k > n

        for (int i = 0; i < k; i++) {
            int first = arr[0];
            for (int j = 0; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = first;
        }
    }
};


//Approach 2: Using Extra Array
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
      void leftRotateExtraArray(vector<int>& arr, int k) {
          int n = arr.size();
          k = k % n;
  
          vector<int> temp(n);
          for (int i = 0; i < n; i++) {
              temp[i] = arr[(i + k) % n];
          }
  
          arr = temp; // copy back
      }
  };

  //Approach 3: Optimal (Reversal Algorithm)
//   Time Complexity: O(n)
// Space Complexity: O(1) ✅

class Solution {
  public:
      void leftRotateReversal(vector<int>& arr, int k) {
          int n = arr.size();
          k = k % n;
  
          // Step 1: Reverse first k elements
          reverse(arr.begin(), arr.begin() + k);
  
          // Step 2: Reverse remaining n-k elements
          reverse(arr.begin() + k, arr.end());
  
          // Step 3: Reverse whole array
          reverse(arr.begin(), arr.end());
      }
  };
  

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    s.leftRotateReversal(arr, k);

    for (int num : arr) cout << num << " ";
    return 0;
}
