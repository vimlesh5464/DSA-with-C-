#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int findMin(vector<int>& nums) {
          int low = 0, high = nums.size() - 1;
      while (low < high) {
          int mid = (low + high)/2;
          if (nums[mid] > nums[high]) low = mid + 1;
          else high = mid;
      }
      return nums[low];
      }
  };

  int main(){
    Solution s;
    int n;
    cin>> n;
    cout<< n<<endl;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
      cin>> nums[i];
    }
    cout<< s.findMin(nums);
    return 0;
  }