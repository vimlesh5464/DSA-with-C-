// 🔹 Approaches
// 1. Counting Sort (Two Pass)
// Count the number of 0s, 1s, and 2s.
// Overwrite the array with correct counts.
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
void sort012(vector<int> &arr) {
  int n = arr.size();
  int c0 = 0, c1 = 0, c2 = 0;

  // count 0s, 1s and 2s
  for (int i = 0; i < n; i++) {
      if (arr[i] == 0)
          c0 += 1;
      else if (arr[i] == 1)
          c1 += 1;
      else
          c2 += 1;
  }

  int idx = 0;
  
  // place all the 0s
  for (int i = 0; i < c0; i++)
      arr[idx++] = 0;

  // place all the 1s
  for (int i = 0; i < c1; i++)
      arr[idx++] = 1;

  // place all the 2s
  for (int i = 0; i < c2; i++)
      arr[idx++] = 2;
}

};

// 2. Dutch National Flag Algorithm (One Pass) ✅Idea:
// Maintain three pointers:
// low → next position for 0
// mid → current element being processed
// high → next position for 2
// Swap elements to move 0s to front and 2s to end in one pass.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
      void sortColors(vector<int>& nums) {
          int low = 0, mid = 0, high = nums.size() - 1;
  
          while(mid <= high){
              if(nums[mid] == 0){
                  swap(nums[low], nums[mid]);
                  low++; mid++;
              }
              else if(nums[mid] == 1){
                  mid++;
              }
              else { // nums[mid] == 2
                  swap(nums[mid], nums[high]);
                  high--;
              }
          }
      }
  };

int main() {
    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    for(int num : nums) cout << num << " ";
    return 0;
}
