// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is 
//nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next
// in the array, which means you could search circularly to find its next greater number. 
//If it doesn't exist, return -1 for this number.

 

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

 

// Constraints:

//     1 <= nums.length <= 104
//     -109 <= nums[i] <= 109

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int> &arr) {
  int n = arr.size();

  vector<int> res(n, -1);
  for (int i = 0; i < n; i++) {

      for (int j = 1; j < n; j++) {

          // Checking for next greater element
          if (arr[i] < arr[(i + j)%n]) {
              res[i] = arr[(i + j)%n];
              break;
          }
      }
  }

  return res;
}

// ✅ Time Complexity: O(n) (each element pushed/popped at most once).
// ✅ Space Complexity: O(n) (for stack).
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;

        // Traverse twice to simulate circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            int num = nums[i % n]; // wrap index

            // Pop smaller or equal elements
            while (!stk.empty() && stk.top() <= num) {
                stk.pop();
            }

            // Only fill answers in first pass
            if (i < n && !stk.empty()) {
                res[i] = stk.top();
            }

            // Push current element
            stk.push(num);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
