#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
         // Sort meetings by start time
        sort(arr.begin(), arr.end());
        
        // Check for overlap
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};