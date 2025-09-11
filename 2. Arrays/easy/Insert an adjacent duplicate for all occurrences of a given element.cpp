#include <iostream>
#include <vector>
using namespace std;

//[Naive Approach] - One by One Insert and Truncate - O(n^2) Time and O(n) Space

vector<int> duplicateK(vector<int> arr, int k) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        if(arr[i] == k) {
            
            // Insert an adjacent k
            arr.insert(arr.begin() + i + 1, k);
            i++;
            
            // Pop the last element
            arr.pop_back();
        }
    }
    return arr;
}

//[Expected Approach] - Using Two Pointer Technique- O(n) Time and O(1) Space
vector<int> duplicateK1(vector<int>& arr,int k)
{
    const int n = arr.size();

    // Find the count of total number of k
    int cnt = count(arr.begin(), arr.end(), k);

    // Variable to store index where elements
    // will be written in the final array
    int write_idx = n + cnt - 1;

    // Variable to point the current index
    int curr = n - 1;

    while (curr >= 0 && write_idx >= 0) {
        
        // Keep the current element to its correct
        // position, if that is within the size N
        if (write_idx < n)
            arr[write_idx] = arr[curr];

        write_idx -= 1;

        // Check if the current element is also
        // k then again write its duplicate
        if (arr[curr] == k) {
            if (write_idx < n)
                arr[write_idx] = k;

            write_idx -= 1;
        }

        --curr;
    }
    return arr;
}

int main() {
    vector<int> arr = { 1, 0, 2, 3, 0, 4, 5, 0 };
    int k = 0;
    vector<int> ans = duplicateK(arr, k);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}