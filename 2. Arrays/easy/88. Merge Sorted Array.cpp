//🔹 Approach 1: Merge From Back (Optimal In-place)Idea:
//Time and Space Complexity : O(m + n) , O(1)
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // last element in nums1 valid part
        int j = n - 1;      // last element in nums2
        int k = m + n - 1;  // last position in nums1

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy remaining elements of nums2, if any
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
};


//Approach 2: Using Extra Array (Not Optimal)
// Time Complexity: O((m+n) log(m+n))
// Space Complexity: O(m+n)


class Solution {
  public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          vector<int> temp;
  
          // Copy valid elements of nums1
          for(int i = 0; i < m; i++)
              temp.push_back(nums1[i]);
  
          // Copy elements of nums2
          for(int i = 0; i < n; i++)
              temp.push_back(nums2[i]);
  
          // Sort the combined array
          sort(temp.begin(), temp.end());
  
          // Copy back to nums1
          for(int i = 0; i < m + n; i++)
              nums1[i] = temp[i];
      }
  };
  
int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    s.merge(nums1, m, nums2, n);

    for(int num : nums1) cout << num << " ";
    return 0;
}
