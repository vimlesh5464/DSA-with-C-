// Given an array arr[] of non-negative integers which may contain duplicate elements.
// Return the frequency of each distinct element present in the array.

// Examples: 

//     Input:  arr[] = [10, 20, 10, 5, 20]
//     Output: [[5, 1], [10, 2], [20, 2]]
//     Explanation: Here 5 occurs once, 10 occurs 2 times and 20 occurs 2 times.

//     Input: arr[] = [10, 20, 20]
//     Output: [[10, 1], [20, 2]] 
//     Explanation: Here 10 occurs 1 time, 20 occurs 2 times.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> countFreq(vector<int>& arr){
    int n = arr.size();
    
    // Mark all array elements as not visited
    vector<bool> visited(n , false);
    vector<vector<int>>ans;
    for (int i = 0; i < n; i++) {
        
        // Skip this element if already processed
        if (visited[i] == true)
            continue;

        // store the frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
            
        }
        ans.push_back({arr[i] , count});
    }
    return ans;
}


vector<vector<int>> countFreq(vector<int> &arr){
    int n = arr.size();
    
    // Sort array for binary search
    sort(arr.begin(), arr.end()); 
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        
        // Find first and last occurrence of arr[i]
        // using lower and upper bound 
        auto firstIter = lower_bound(arr.begin(), arr.end(), arr[i]);
        auto lastIter = upper_bound(arr.begin(), arr.end(), arr[i]);
        int firstIndex = firstIter - arr.begin();
        int lastIndex = lastIter - arr.begin() - 1;
        
        // Calculate frequency
        int fre = lastIndex - firstIndex + 1; 
        ans.push_back({arr[i], fre}); 
        
        // Skip counted elements
        i = lastIndex; 
    }
    return ans;
}


vector<vector<int>> countFreq(vector<int>& arr) {
    
    // stores frequency of each number
    unordered_map<int, int> mp;      
    // stores {number, frequency}
    vector<vector<int>> ans;         

    // count frequency using unordered_map
    for (int num : arr) {
        mp[num]++;
    }

    // build the answer vector from the frequency map
    for (auto &it : mp) {
        ans.push_back({it.first, it.second});
    }

    return ans ;
}

int main() {
    vector<int> arr = {10, 20, 10, 5, 20};

    vector<vector<int>> ans = countFreq(arr);

    // sort the result in ascending order of the number
    sort(ans.begin(), ans.end(), [](vector<int>& a, 
                        vector<int>& b) {
        return a[0] < b[0];  
    });

    for (auto &x : ans) {
        cout << x[0] << " " << x[1] << endl;
    }

    return 0;
}