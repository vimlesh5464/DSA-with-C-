#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * @brief Finds the single element in a sorted array where every other element appears twice.
 * * The binary search is designed to search the half where the single element lies.
 * Before the single element: (Even index, Odd index) form a pair.
 * After the single element: (Odd index, Even index) form a pair.
 * * @param nums The input vector of integers.
 * @return The single non-duplicate element.
 */
int singleNonDuplicate(vector<int>& nums) {
    // Search space is from index 0 to size-2 because if the single element 
    // is the last one, the binary search will naturally converge to it.
    int low = 0, high = nums.size() - 2; 

    while (low <= high) {
        int mid = low + (high - low) / 2; // Safer way to calculate mid

        if (mid % 2 == 0) {
            // Mid is an even index. Its pair should be at mid + 1.
            if (nums[mid] == nums[mid + 1]) {
                // The pair is found. This means the single element is to the right.
                // We discard mid and mid+1 and move low past the pair.
                low = mid + 2; 
            } else {
                // nums[mid] != nums[mid + 1]. The pair pattern is broken.
                // This means the single element is at or before mid.
                high = mid - 1;
            }
        } else {
            // Mid is an odd index. Its pair should be at mid - 1.
            if (nums[mid] == nums[mid - 1]) {
                // The pair is found. This means the single element is to the right.
                // We discard mid and mid-1 and move low past mid.
                low = mid + 1; 
            } else {
                // nums[mid] != nums[mid - 1]. The pair pattern is broken.
                // This means the single element is at or before mid.
                high = mid - 1;
            }
        }
    }
    // 'low' will be the starting index of the sub-array containing the single element, 
    // which, due to the search pattern, will converge to the index of the non-duplicate element.
    return nums[low];
}

// Main function for user input and output
int main() {
    cout << "Enter the number of elements (must be odd, e.g., 7): ";
    int n;
    if (!(cin >> n) || n <= 0 || n % 2 == 0) {
        cerr << "Invalid input. Please enter a positive odd number." << endl;
        return 1;
    }

    cout << "Enter the elements (sorted, with one single element, e.g., 1 1 2 3 3 4 4):" << endl;
    vector<int> nums;
    
    for (int i = 0; i < n; ++i) {
        int val;
        if (!(cin >> val)) {
            cerr << "Invalid element input." << endl;
            return 1;
        }
        nums.push_back(val);
    }
    
    // Validate the input size (for safety, though not strictly needed for the logic)
    if (nums.empty()) {
        cout << "The list is empty. No single non-duplicate element." << endl;
        return 0;
    }

    int result = singleNonDuplicate(nums);

    cout << "\nInput Array: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    cout << "The single non-duplicate element is: **" << result << "**" << endl;

    return 0;
}