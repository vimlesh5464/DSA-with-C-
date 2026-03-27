#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int>& arr) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int start = arr[0]; // starting number

  while (low <= high) {
      int mid = low + (high - low) / 2;

      // If the number of elements till mid is equal to expected count
      if (arr[mid] == start + mid) {
          // Missing element is on right
          low = mid + 1;
      } else {
          // Missing element is on left
          high = mid - 1;
      }
  }

  // At the end, missing number = starting number + low
  return start + low;
}
int main() {
    vector<int> arr = { 1, 2, 3, 4, 6, 7, 8 };
    cout << findMissing(arr);
}