#include <iostream>
#include <vector>
using namespace std;

//[Approach 1] Using Visited Array - O(n) Time and O(n) Space
vector<int> findTwoElement(vector<int>& arr) {
    
    int n = arr.size();  
    // frequency array to count occurrences
    vector<int> freq(n + 1, 0); 
    int repeating = -1, missing = -1;
    
    // count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // identify repeating and missing elements
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) missing = i;
        else if (freq[i] == 2) repeating = i;
    }
    
    return {repeating, missing};
}

//[Approach 4] Using XOR - O(n) Time and O(1) Space
vector<int> findTwoElement(vector<int>& arr) {
  int n = arr.size();
  int xorVal = 0;  

  // get the xor of all array elements
  // and numbers from 1 to n
  for (int i = 0; i < n; i++) {
      xorVal ^= arr[i];
      xorVal ^= (i + 1);  // 1 to n numbers
  }

  // get the rightmost set bit in xorVal
  int setBitIndex = xorVal & ~(xorVal - 1);
  
  int x = 0, y = 0;

  // now divide elements into two sets 
  // by comparing rightmost set bit
  for (int i = 0; i < n; i++) {
    
      // decide whether arr[i] is in first set 
      // or second
      if (arr[i] & setBitIndex) { 
          x ^= arr[i]; 
      }  
      else { 
          y ^= arr[i]; 
      } 
    
      // decide whether (i+1) is in first set 
      // or second
      if ((i+1) & setBitIndex) { 
          x ^= (i + 1); 
      }
      else { 
          y ^= (i + 1); 
      }
  }

  // x and y are the repeating and missing values.
  // to know which one is what, traverse the array 
  int missing, repeating;
  
  int xCnt = 0;
  for (int i=0; i<n; i++) {
      if (arr[i] == x) {
          xCnt++;
      }
  }
  
  if (xCnt == 0) {
      missing = x;
      repeating = y;
  }
  else {
      missing = y;
      repeating = x;
  }
  
  return {repeating, missing};
}

int main() {
    vector<int> arr = {3, 1, 3};
    vector<int> ans = findTwoElement(arr);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}