// Next Greater Element in Circular Array
// Difficulty: MediumAccuracy: 56.97%Submissions: 60K+Points: 4

// Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.

// The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.

// Note: Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

// Examples: 

// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation:
// The next greater element for 1 is 3.
// The next greater element for 3 is 4.
// The next greater element for 2 is 4.
// The next greater element for 4 does not exist, so return -1.

// Input: arr[] = [0, 2, 3, 1, 1]
// Output: [2, 3, -1, 2, 2]
// Explanation:
// The next greater element for 0 is 2.
// The next greater element for 2 is 3.
// The next greater element for 3 does not exist, so return -1.
// The next greater element for 1 is 2 (from circular traversal).
// The next greater element for 1 is 2 (from circular traversal).

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 106

#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);  // initialize with -1

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[j] > arr[i]) {
                    ans[i] = arr[j];
                    break;  // stop at first greater
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(N)

// Space Complexity: O(N)


class Solution {
  public:
    vector < int >nextGreater(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {4, 5, 2, 25};

    // Function call
    vector<int> result = sol.nextGreater(arr);

    // Print output
    cout << "Next Greater Elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
