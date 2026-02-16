#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> storeAllSubarrays(vector<int>& arr) {
  int n = arr.size();
  vector<vector<int>> result;

  for (int start = 0; start < n; start++) {
      for (int end = start; end < n; end++) {
          vector<int> subarray;
          for (int i = start; i <= end; i++) {
              subarray.push_back(arr[i]);
          }
          result.push_back(subarray);
      }
  }
  return result;
}



vector<vector<int>> allSubarrays(vector<int>& arr) {
  int n = arr.size();
  vector<vector<int>> result;

  for (int i = 0; i < n; i++) {
      vector<int> temp;
      for (int j = i; j < n; j++) {
          temp.push_back(arr[j]);
          result.push_back(temp);
      }
  }
  return result;
}

int totalSubarrays(int n) {
  return n * (n + 1) / 2;
}
