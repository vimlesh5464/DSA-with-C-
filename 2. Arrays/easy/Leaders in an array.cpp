#include <iostream>
#include <vector>
using namespace std;

//[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space:
// Function to find the leaders in an array
vector<int> leaders(vector<int>& arr) {
    vector<int> res;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int j;

        // Check elements to the right
        // of the current element
        for (j = i + 1; j < n; j++) {

            // If a larger element is found,
            // break the loop
            if (arr[i] < arr[j])
                break;
        }

        // If no larger element was found,
        // the current element is a leader
        if (j == n) 
            res.push_back(arr[i]);
    }
    
    return res;
}

//[Expected Approach] Using Suffix Maximum - O(n) Time and O(1) Space:
vector<int> leaders(vector<int>& arr) {
  vector<int> res; 
  int n = arr.size();

  // Start with the rightmost element
  int maxRight = arr[n - 1]; 

  // Rightmost element is always a leader
  res.push_back(maxRight); 
  
  // Traverse the array from right to left
  for (int i = n - 2; i >= 0; i--) {

      if (arr[i] >= maxRight) {
          maxRight = arr[i]; 
          res.push_back(maxRight); 
      }
  }

  // Reverse the result array to maintain
  // original order
  reverse(res.begin(), res.end());
  
  return res; 
}
int main() {
    vector<int> arr = { 16, 17, 4, 3, 5, 2 };
    vector<int> result = leaders(arr);
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}