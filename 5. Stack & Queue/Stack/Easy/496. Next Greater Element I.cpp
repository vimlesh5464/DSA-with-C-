#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
  public:
      vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
          vector<int> res(nums1.size(), -1);
  
          for (int i = 0; i < nums1.size(); i++) {
              for (int j = 0; j < nums2.size(); j++) {
  
                  // find nums1[i] in nums2
                  if (nums2[j] == nums1[i]) {
  
                      // search on the right side
                      for (int k = j + 1; k < nums2.size(); k++) {
                          if (nums2[k] > nums1[i]) {
                              res[i] = nums2[k];
                              break;
                          }
                      }
                      break; // nums1[i] found, no need to continue j
                  }
              }
          }
          return res;
      }
  };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; // store next greater for nums2 elements
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            if (!st.empty()) {
                mp[num] = st.top();
            } else {
                mp[num] = -1;
            }
            st.push(num);
        }

        // Build answer for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans; 
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
