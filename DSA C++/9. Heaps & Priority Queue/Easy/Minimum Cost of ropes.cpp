
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

// Examples:

// Input: arr[] = [4, 3, 2, 6]
// Output: 29
// Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, giving a total minimum cost of 29. Any other order, such as connecting 4 and 6 first, results in a higher total cost of 38.

// Input: arr[] = [4, 2, 7, 6, 9]
// Output: 62 
// Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12. Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.

// Input: arr[] = [10]
// Output: 0
// Explanation: Since there is only one rope, no connections are needed, so the cost is 0.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104




#include <queue>
#include <vector>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& arr) {
        int totalCost = 0;

        while (arr.size() > 1) {
            sort(arr.begin(), arr.end()); // हर बार sort ❌

            int first = arr[0];
            int second = arr[1];

            int sum = first + second;
            totalCost += sum;

            arr.erase(arr.begin());
            arr.erase(arr.begin());
            arr.push_back(sum);
        }

        return totalCost;
    }
};


class Solution {
public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 1: push all ropes
        for (int x : arr) {
            minHeap.push(x);
        }

        int totalCost = 0;

        // Step 2: connect ropes
        while (minHeap.size() > 1) {
            int first = minHeap.top(); minHeap.pop();
            int second = minHeap.top(); minHeap.pop();

            int cost = first + second;
            totalCost += cost;

            minHeap.push(cost);
        }

        return totalCost;
    }
};