#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        vector<pair<int,int>> vp;

        // Step 1: store value and original index
        for(int i = 0; i < n; i++){
            vp.push_back({arr[i], i});
        }

        // Step 2: sort by value
        sort(vp.begin(), vp.end());

        // Step 3: check displacement
        for(int i = 0; i < n; i++){
            int originalIndex = vp[i].second;
            int sortedIndex = i;
            if(abs(originalIndex - sortedIndex) > k)
                return "No";  // Not k-sorted
        }

        return "Yes"; // k-sorted
    }
};
class Solution {
public:
    string isKSortedArray(int arr[], int n, int k) {
        vector<int> sortedArr; // simulate sorted array using heap

        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 1: push first k+1 elements
        for(int i = 0; i <= min(k, n-1); i++)
            pq.push(arr[i]);

        int index = 0;

        // Step 2: iterate remaining elements
        for(int i = k+1; i < n; i++) {
            // top of min-heap must go next
            sortedArr.push_back(pq.top());
            pq.pop();

            pq.push(arr[i]);
        }

        // Step 3: pop remaining elements from heap
        while(!pq.empty()) {
            sortedArr.push_back(pq.top());
            pq.pop();
        }

        // Step 4: check if sortedArr matches fully sorted version
        vector<int> check(arr, arr+n);
        sort(check.begin(), check.end());

        if(sortedArr == check)
            return "Yes";
        else
            return "No";
    }
};
int main() {
  int arr[] = {3, 2, 1, 5, 6, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 2;

  Solution sol;
  cout << sol.isKSortedArray(arr, n, k) << endl; // Output: Yes

  int arr2[] = {13, 8, 10, 7, 15, 14, 12};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  int k2 = 1;
  cout << sol.isKSortedArray(arr2, n2, k2) << endl; // Output: No

  return 0;
}
