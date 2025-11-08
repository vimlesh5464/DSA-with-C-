#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

public:
    // Constructor
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    // Add val to nums2[index]
    void add(int index, int val) {
        int oldVal = nums2[index];
        int newVal = oldVal + val;

        // Update frequency map
        freq2[oldVal]--;
        if (freq2[oldVal] == 0) {
            freq2.erase(oldVal);
        }

        freq2[newVal]++;
        nums2[index] = newVal;
    }

    // Count pairs (i, j) such that nums1[i] + nums2[j] == tot
    int count(int tot) {
        int result = 0;
        for (int num1 : nums1) {
            int complement = tot - num1;
            if (freq2.count(complement)) {
                result += freq2[complement];
            }
        }
        return result;
    }
};
