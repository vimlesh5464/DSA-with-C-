// Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

// Examples:

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: [1, 2, 3, 4, 5, 6, 7]
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

// Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
// Output: [1, 2, 3, 4, 5]
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.

// Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
// Output: [1, 2]
// Explanation: Distinct elements including both the arrays are: 1 2.

// Constraints:
// 1  ≤  a.size(), b.size()  ≤  105
// -109 ≤ a[i], b[i] ≤109


#include <iostream>
#include <vector>
#include<set>
using namespace std;
vector<int> unionArray(vector<int>& a, vector<int>& b) {
  set<int> st;

  for (int x : a) st.insert(x);
  for (int x : b) st.insert(x);

  return vector<int>(st.begin(), st.end());
}

vector<int> unionArray(vector<int>& a, vector<int>& b) {
  int i = 0, j = 0;
  vector<int> ans;

  while (i < a.size() && j < b.size()) {
      // avoid duplicates
      if (i > 0 && a[i] == a[i - 1]) {
          i++;
          continue;
      }
      if (j > 0 && b[j] == b[j - 1]) {
          j++;
          continue;
      }

      if (a[i] < b[j]) {
          ans.push_back(a[i]);
          i++;
      }
      else if (a[i] > b[j]) {
          ans.push_back(b[j]);
          j++;
      }
      else {
          // equal
          ans.push_back(a[i]);
          i++;
          j++;
      }
  }

  // remaining elements of a
  while (i < a.size()) {
      if (i == 0 || a[i] != a[i - 1]) {
          ans.push_back(a[i]);
      }
      i++;
  }

  // remaining elements of b
  while (j < b.size()) {
      if (j == 0 || b[j] != b[j - 1]) {
          ans.push_back(b[j]);
      }
      j++;
  }

  return ans;
}