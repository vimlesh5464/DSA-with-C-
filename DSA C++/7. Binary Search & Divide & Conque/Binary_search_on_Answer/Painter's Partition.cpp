// Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

// Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

// Examples:

// Input: arr[] = [5, 10, 30, 20, 15], k = 3
// Output: 35
// Explanation: The optimal allocation of boards among 3 painters is - 
// Painter 1 → [5, 10] → time = 15
// Painter 2 → [30] → time = 30
// Painter 3 → [20, 15] → time = 35
// Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35

// Input: arr[] = [10, 20, 30, 40], k = 2
// Output: 60
// Explanation: A valid optimal partition is - 
// Painter 1 → [10, 20, 30] → time = 60
// Painter 2 → [40] → time = 40
// Job will be complete at time = max(60, 40) = 60

// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 1000
// Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104
// 1 ≤ k ≤ 105


#include<iostream>
#include<vector>
#include <numeric>  
using namespace std;
// Class to solve the Painter Partition Problem
class PainterPartition {
public:
    // Helper function to count how many painters are required to paint the boards within the given time limit
    int countPainters(vector<int> &boards, int time) {
        int n = boards.size();
        int painters = 1; // Start with one painter
        long long boardsPainter = 0; // Current total board length assigned to a painter

        for (int i = 0; i < n; i++) {
            if (boardsPainter + boards[i] <= time) {
                // If current board can be assigned to the same painter
                boardsPainter += boards[i];
            } else {
                // Otherwise, assign it to the next painter
                painters++;
                boardsPainter = boards[i];
            }
        }
        return painters;
    }

    // Function to find the minimum time to paint all boards using at most k painters
    int findLargestMinDistance(vector<int> &boards, int k) {
        int low = *max_element(boards.begin(), boards.end()); // Min possible time = largest board
        int high = accumulate(boards.begin(), boards.end(), 0); // Max time = total sum of boards

        for (int time = low; time <= high; time++) {
            if (countPainters(boards, time) <= k) {
                return time;
            }
        }
        return low;
    }
};

// Class to solve the Painter Partition Problem using Binary Search
class PainterPartition {
public:
    // Helper function: counts how many painters are needed if each can paint at most 'time' units
    int countPainters(vector<int> &boards, int time) {
        int painters = 1;
        long long boardsPainter = 0;

        for (int i = 0; i < boards.size(); i++) {
            if (boardsPainter + boards[i] <= time) {
                // Allocate board to current painter
                boardsPainter += boards[i];
            } else {
                // Allocate board to new painter
                painters++;
                boardsPainter = boards[i];
            }
        }

        return painters;
    }

    // Main function: finds the minimum max time using binary search
    int findLargestMinDistance(vector<int> &boards, int k) {
        int low = *max_element(boards.begin(), boards.end());      // At least the largest board
        int high = accumulate(boards.begin(), boards.end(), 0);    // At most the total sum

        int result = high;

        while (low <= high) {
            int mid = (low + high) / 2;  // Mid time to test
            int painters = countPainters(boards, mid);

            if (painters > k) {
                low = mid + 1; // Too few painters → increase time
            } else {
                result = mid;  // Valid solution → try to minimize
                high = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    PainterPartition pp;
    int ans = pp.findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n"; // Expected: 60
    return 0;
}

