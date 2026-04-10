// Topics
// premium lock iconCompanies

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


#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> freqList; // {element, frequency}
        int n = nums.size();

        // Step 1: Count frequency using brute force
        for (int i = 0; i < n; i++) {
            int count = 0;

            // check if already counted
            bool alreadyPresent = false;
            for (auto &p : freqList) {
                if (p.first == nums[i]) {
                    alreadyPresent = true;
                    break;
                }
            }

            if (alreadyPresent) continue;

            // count frequency
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            freqList.push_back({nums[i], count});
        }

        // Step 2: Sort by frequency (descending)
        sort(freqList.begin(), freqList.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 3: Take top k
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqList[i].first);
        }

        return result;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Min heap: {frequency, number}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for (auto &p : freq) {
            minHeap.push({p.second, p.first});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};