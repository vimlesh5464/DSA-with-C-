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
    void sortColors(vector<int>& nums) {
        int count[3] = {0};  // count[0]=0s, count[1]=1s, count[2]=2s

        for(int num : nums) count[num]++;

        int index = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < count[i]; j++){
                nums[index++] = i;
            }
        }
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
