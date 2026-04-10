// You are given an array nums consisting of positive integers.

// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

// The frequency of an element is the number of occurrences of that element in the array.

 

// Example 1:

// Input: nums = [1,2,2,3,1,4]
// Output: 4
// Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
// So the number of elements in the array with maximum frequency is 4.

// Example 2:

// Input: nums = [1,2,3,4,5]
// Output: 5
// Explanation: All elements of the array have a frequency of 1 which is the maximum.
// So the number of elements in the array with maximum frequency is 5.

 

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i] <= 100

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int maxFreq = 0;

        // Step 1: Find max frequency
        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count > maxFreq) {
                maxFreq = count;
            }
        }

        // Step 2: Count total elements having max frequency
        int total = 0;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count == maxFreq) {
                total += count;
            }
        }

        return total;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Find max frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        // Step 3: Sum frequencies of max elements
        int total = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                total += p.second;
            }
        }

        return total;
    }
};