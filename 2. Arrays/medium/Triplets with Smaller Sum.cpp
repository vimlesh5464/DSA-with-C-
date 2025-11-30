#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        long long count = 0;

        // Sort the array
        sort(arr, arr + n);

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                long long currSum = arr[i] + arr[left] + arr[right];

                if(currSum < sum) {
                    // All triplets from left to right with arr[i] are valid
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }

        return count;
    }
};

int main() {
    int n;
    long long sum;
    
    cout << "Enter size of array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    Solution sol;
    long long result = sol.countTriplets(n, sum, arr);

    cout << "Number of triplets with sum less than " << sum << " is: " << result << endl;

    return 0;
}
