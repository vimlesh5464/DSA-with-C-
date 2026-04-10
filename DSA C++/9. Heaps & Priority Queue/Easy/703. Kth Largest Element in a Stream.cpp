// GFG version
// Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element) after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion.  return a list of size n after all insertions.

// Example 1:

// Input:
// k = 4, n = 6
// arr[] = {1, 2, 3, 4, 5, 6}
// Output:
// -1 -1 -1 1 2 3
// Explanation:
// k = 4
// For 1, the 4th largest element doesn't
// exist so answer will be -1.
// For 2, the 4th largest element doesn't
// exist so answer will be -1.
// For 3, the 4th largest element doesn't
// exist so answer will be -1.
// For 4, the 4th largest element is 1.
// For 5, the 4th largest element is 2.
// for 6, the 4th largest element is 3.

// Example 2:

// Input:
// k = 1, n = 2
// arr[] = {3, 4}
// Output:
// 3 4 
// Explanation: 
// For the 1st and 2nd element the 1st largest 
// element is itself.

 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes 2 Integers k, and n and also an array arr[] of size n as input. After the insertion of each element find Kth largest element in the stream and if the Kth element doesn't exist, the answer will be -1 for that insertion.  return a list of size n after all insertions.

 

// Expected Time Complexity: O(nlogk)
// Expected Auxiliary Space: O(n)

 

// Constraints:
// 1 ≤ k ≤ n ≤ 105
// 1 ≤ arr[i] ≤ 105
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            minHeap.push(arr[i]);

            if (minHeap.size() > k) {
                minHeap.pop();
            }

            if (minHeap.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(minHeap.top());
            }
        }

        return result;
    }
};


//Leetcode version 
// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

// Implement the KthLargest class:

//     KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
//     int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

 

// Example 1:

// Input:
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

// Output: [null, 4, 5, 5, 8, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3); // return 4
// kthLargest.add(5); // return 5
// kthLargest.add(10); // return 5
// kthLargest.add(9); // return 8
// kthLargest.add(4); // return 8

// Example 2:

// Input:
// ["KthLargest", "add", "add", "add", "add"]
// [[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

// Output: [null, 7, 7, 7, 8]

// Explanation:
// KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
// kthLargest.add(2); // return 7
// kthLargest.add(10); // return 7
// kthLargest.add(9); // return 7
// kthLargest.add(9); // return 8

 

// Constraints:

//     0 <= nums.length <= 104
//     1 <= k <= nums.length + 1
//     -104 <= nums[i] <= 104
//     -104 <= val <= 104
//     At most 104 calls will be made to add.

class KthLargest {
  public:
      int k;
      priority_queue<int, vector<int>, greater<int>> minHeap;
      KthLargest(int k, vector<int>& nums) {
          this->k = k;
  
          // Add all elements to heap
          for (int num : nums) {
              minHeap.push(num);
  
              // Maintain size k
              if (minHeap.size() > k) {
                  minHeap.pop();
              }
          }
      }
      
      int add(int val) {
          minHeap.push(val);
  
          // Maintain size k
          if (minHeap.size() > k) {
              minHeap.pop();
          }
  
          // Top is kth largest
          return minHeap.top();
      }
  };
  