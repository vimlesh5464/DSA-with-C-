#include<iostream>
#include <vector>
#include <stack>
using namespace std;
//leetcode version
class Solution {
public:
    int maxPeople(std::vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        int maxVisible = 1;
        
        for (int i = 0; i < n; i++) {
            int currentVisible = 1; // Including self
            
            // Look Right: Count consecutive elements smaller than arr[i]
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[i]) {
                    currentVisible++;
                } else {
                    break; // Blocked by someone taller or equal
                }
            }
            
            // Look Left: Count consecutive elements smaller than arr[i]
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < arr[i]) {
                    currentVisible++;
                } else {
                    break; // Blocked by someone taller or equal
                }
            }
            
            maxVisible = max(maxVisible, currentVisible);
        }
        
        return maxVisible;
    }
};

//gfg version
class Solution {
  public:
      int maxPeople(vector<int> &arr) {
          int n = arr.size();
          if (n == 0) return 0;
  
          // nearestLeft[i] will store the index of the first person >= arr[i] to the left
          vector<int> nearestLeft(n, -1);
          // nearestRight[i] will store the index of the first person >= arr[i] to the right
          vector<int> nearestRight(n, n);
  
          stack<int> s;
  
          // Find nearest larger or equal to the left
          for (int i = 0; i < n; i++) {
              while (!s.empty() && arr[s.top()] < arr[i]) {
                  s.pop();
              }
              if (!s.empty()) {
                  nearestLeft[i] = s.top();
              }
              s.push(i);
          }
  
          // Clear stack for reuse
          while(!s.empty()) s.pop();
  
          // Find nearest larger or equal to the right
          for (int i = n - 1; i >= 0; i--) {
              while (!s.empty() && arr[s.top()] < arr[i]) {
                  s.pop();
              }
              if (!s.empty()) {
                  nearestRight[i] = s.top();
              }
              s.push(i);
          }
  
          int maxVisible = 0;
          for (int i = 0; i < n; i++) {
              // Count = (right_boundary - left_boundary - 1)
              // Example: left index 0, right index 6, current index 3
              // People seen are indices 1, 2, 3, 4, 5. Total = 6 - 0 - 1 = 5
              int currentVisible = nearestRight[i] - nearestLeft[i] - 1;
              maxVisible = max(maxVisible, currentVisible);
          }
  
          return maxVisible;
      }
  };