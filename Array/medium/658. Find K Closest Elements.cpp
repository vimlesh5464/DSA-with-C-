//Approach 1: Sorting by Distance

#include <iostream>
#include<vector>
using namespace std;
//✅ Time Complexity: O(n log n)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Sort array by distance from x
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            if (abs(a - x) == abs(b - x)) return a < b;  // if tie, smaller element first
            return abs(a - x) < abs(b - x);
        });

        // Take first k elements
        vector<int> result(arr.begin(), arr.begin() + k);

        // Sort result to keep ascending order
        sort(result.begin(), result.end());
        return result;
    }
};

//Approach 2: Binary Search + Two Pointers
class Solution {
  public:
      vector<int> findClosestElements(vector<int>& arr, int k, int x) {
          int n = arr.size();
          
          // Find the insert position of x
          int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
          int left = right - 1;
  
          // Expand k elements
          while (k--) {
              if (left < 0) right++;
              else if (right >= n) left--;
              else if (abs(arr[left] - x) <= abs(arr[right] - x)) left--;
              else right++;
          }
  
          // Collect result
          return vector<int>(arr.begin() + left + 1, arr.begin() + right);
      }
  };
  
  int main() {
      Solution s;
      vector<int> arr = {1, 2, 3, 4, 5};
      int k = 4, x = 3;
      vector<int> ans = s.findClosestElements(arr, k, x);
  
      for (int num : ans) cout << num << " ";
      return 0;
  }
  
  // ✅ Time Complexity: O(log n + k)
  
  // ⚖️ Which to prefer?
  
  //     For coding interviews / LeetCode → use Approach 2 (Binary Search + Two Pointers).
  
  //     For learning / simple coding → Approach 1 is easier.
  
  // Do you want me to dry run both codes with input [1,2,3,4,5], k=4, x=6 so you see the difference step by step?
  
  
  

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    vector<int> ans = s.findClosestElements(arr, k, x);
    
    for (int num : ans) cout << num << " ";
    return 0;
}
