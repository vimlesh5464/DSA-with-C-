// Given an integer array, arr. Display the count of AND triplets.
// An AND triplet is a set of three indices i, j, and k such that:

// 0 <= i < arr.length
// 0 <= j < arr.length
// 0 <= k < arr.length
// The bitwise AND of the elements at these indices equals zero, i.e., arr[i] & arr[j] & arr[k] == 0, where & denotes the bitwise AND operator.
 

// Input Format

// The first line contains an integer N, the number of elements in the array.
// The second line contains N integers, representing the elements of the array arr.

// Output Format

// Print a single integer: the number of AND triplets in the array.

// Constraints

// 1 <= N <= 10^3
// 0 <= arr[i] < 216

// Sample Testcase 0

// Testcase Input
// 2
// 1 2 
// Testcase Output
// 6
// Explanation

// Explanation: The array is [1, 2]. The possible triplets (i, j, k) are:



// (i=0, j=0, k=1) → 1 & 1 & 2 = 0

// (i=0, j=1, k=1) → 1 & 2 & 2 = 0

// (i=1, j=0, k=1) → 2 & 1 & 2 = 0

// (i=1, j=1, k=0) → 2 & 2 & 1 = 0

// (i=0, j=1, k=0) → 1 & 2 & 1 = 0

// (i=1, j=0, k=0) → 2 & 1 & 1 = 0


// There are 6 valid triplets in total.
// Sample Testcase 1

// Testcase Input
// 3
// 2 1 3 
// Testcase Output
// 12
// Explanation



// Explanation: The array is [2, 1, 3]. We need to check all possible triplets (i, j, k):



// (i=0, j=0, k=0) → 2 & 2 & 2 = 2

// (i=0, j=0, k=1) → 2 & 2 & 1 = 0

// (i=0, j=0, k=2) → 2 & 2 & 3 = 2

// (i=0, j=1, k=0) → 2 & 1 & 2 = 0

// (i=0, j=1, k=1) → 2 & 1 & 1 = 0

// (i=0, j=1, k=2) → 2 & 1 & 3 = 0

// (i=0, j=2, k=0) → 2 & 3 & 2 = 0

// (i=0, j=2, k=1) → 2 & 3 & 1 = 0

// (i=0, j=2, k=2) → 2 & 3 & 3 = 2

// (i=1, j=0, k=0) → 1 & 2 & 2 = 0

// (i=1, j=0, k=1) → 1 & 2 & 1 = 0

// (i=1, j=0, k=2) → 1 & 2 & 3 = 0

// (i=1, j=1, k=0) → 1 & 1 & 2 = 0

// (i=1, j=1, k=1) → 1 & 1 & 1 = 1

// (i=1, j=1, k=2) → 1 & 1 & 3 = 1

// (i=1, j=2, k=0) → 1 & 3 & 2 = 0

// (i=1, j=2, k=1) → 1 & 3 & 1 = 0

// (i=1, j=2, k=2) → 1 & 3 & 3 = 1

// (i=2, j=0, k=0) → 3 & 2 & 2 = 0

// (i=2, j=0, k=1) → 3 & 2 & 1 = 0

// (i=2, j=0, k=2) → 3 & 2 & 3 = 2

// (i=2, j=1, k=0) → 3 & 1 & 2 = 0

// (i=2, j=1, k=1) → 3 & 1 & 1 = 1

// (i=2, j=1, k=2) → 3 & 1 & 3 = 1

// (i=2, j=2, k=0) → 3 & 3 & 2 = 2

// (i=2, j=2, k=1) → 3 & 3 & 1 = 1

// (i=2, j=2, k=2) → 3 & 3 & 3 = 3


// The valid triplets that result in 0 are:



// (i=0, j=0, k=1)

// (i=0, j=1, k=0)

// (i=0, j=1, k=2)

// (i=0, j=2, k=0)

// (i=0, j=2, k=1)

// (i=1, j=0, k=0)

// (i=1, j=0, k=1)

// (i=1, j=0, k=2)

// (i=1, j=1, k=0)

// (i=1, j=2, k=0)

// (i=1, j=2, k=1)

// (i=2, j=0, k=0)

// (i=2, j=0, k=1)

// (i=2, j=1, k=0)


// There are 12 valid triplets in total.

#include <iostream>
#include <vector>
using namespace std;

int countTriplets(int n, vector<int>& arr) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if ((arr[i] & arr[j] & arr[k]) == 0) {  // use bitwise AND &
                    count++;
                }
            }
        }
    }

    return count;
}

int countTriplets(vector<int>& arr) {
  int n = arr.size();
  
  // Step 1: Count frequency of each number
  unordered_map<int, int> freq;
  for (int num : arr) {
      freq[num]++;
  }
  
  long long total = 0; // Use long long to avoid overflow
  
  // Step 2: Iterate over all pairs (i, j)
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          int mask = arr[i] & arr[j];
          
          // Step 3: Count numbers c where (mask & c) == 0
          for (auto& p : freq) {
              int c = p.first;
              int countC = p.second;
              if ((mask & c) == 0) {
                  total += countC;
              }
          }
      }
  }
  
  return total;
}
int countTriplets(vector<int>& nums) {
  int n = nums.size();
   const int MAX_MASK = 1 << 16;
   vector<int> freq(MAX_MASK, 0);

   // Step 1: Count all pair AND results
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           freq[nums[i] & nums[j]]++;
       }
   }

   // Step 2: Count valid triples
   int total = 0;
   for (int k = 0; k < n; k++) {
       int x = nums[k];
       for (int mask = 0; mask < MAX_MASK; mask++) {
           if ((mask & x) == 0) {
               total += freq[mask];
           }
       }
   }

   return total;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countTriplets(n, arr);
    cout << result << endl;

    return 0;
}