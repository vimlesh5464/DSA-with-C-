#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Time: O(n)

// Space: O(n)
class Solution {
  public:
      bool containsNearbyDuplicate(vector<int>& nums, int k) {
          unordered_map<int, int> lastIndex; // stores number -> last seen index
  
          for (int i = 0; i < nums.size(); i++) {
              int num = nums[i];
              if (lastIndex.find(num) != lastIndex.end()) {
                  if (i - lastIndex[num] <= k) {
                      return true;
                  }
              }
              lastIndex[num] = i; // update last seen index
          }
  
          return false;
      }
  };


// Time: O(n)

// Space: O(k)
  class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_set<int> window;
    
            for (int i = 0; i < nums.size(); i++) {
                // If duplicate found within window
                if (window.count(nums[i])) {
                    return true;
                }
    
                window.insert(nums[i]);
    
                // Maintain window size <= k
                if (window.size() > k) {
                    window.erase(nums[i - k]);
                }
            }
            return false;
        }
    };
    int main() {
      int n, k;
      cin >> n;           // size of array
      vector<int> nums(n);
  
      for (int i = 0; i < n; i++) {
          cin >> nums[i]; // array elements
      }
  
      cin >> k;           // value of k
  
      Solution sol;
      cout << (sol.containsNearbyDuplicate(nums, k) ? "true" : "false");
  
      return 0;
  }