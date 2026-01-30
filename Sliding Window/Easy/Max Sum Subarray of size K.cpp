#include <iostream>
#include <vector>
using namespace std;
// Time: O(n × k)

// Space: O(1)
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        long long maxSum = 0;
        int n = arr.size();

        for(int i = 0; i <= n - k; i++){
            long long sum = 0;
            for(int j = i; j < i + k; j++){
                sum += arr[j];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum; 
    }
};

// Time: O(n)

// Space: O(1)
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0, maxSum = 0;

        // Initial window of size k
        for(int j = 0; j < k; j++){
            sum += arr[j];
        }
        maxSum = sum;

        int i = 0, j = k;

        // Slide the window
        while(j < n){
            sum += arr[j];   // add next element
            sum -= arr[i];   // remove previous element
            i++;
            j++;
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
int main() {
  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
      cin >> arr[i];
  }

  Solution sol;
  cout << sol.maxSubarraySum(arr, k);

  return 0;
}
