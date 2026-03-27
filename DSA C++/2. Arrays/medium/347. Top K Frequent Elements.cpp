// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1

// Output: [1]

// Example 3:

// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// Output: [1,2]

 

// Constraints:

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104
//     k is in the range [1, the number of unique elements in the array].
//     It is guaranteed that the answer is unique.

 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int num : nums) freq[num]++;

    vector<pair<int,int>> v;
    for(auto &p : freq) {
        v.push_back({p.first, p.second});
    }

    // Custom sort: higher frequency first, if same frequency larger element first
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });

    vector<int> ans;
    for(int i=0; i<k; i++) {
        ans.push_back(v[i].first);
    }
    return ans;
}

int main() {
    int N = 8;
    vector<int> nums = {1,1,2,2,3,3,3,4};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    for(int x : result) cout << x << " ";
    return 0;
}
