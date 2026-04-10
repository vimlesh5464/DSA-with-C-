// You are given an array/list ‘ARR’ of ‘N’ positive integers where each element describes the length of the stick. You have to connect all sticks into one. At a time, you can join any two sticks by paying a cost of ‘X’ and ‘Y’ where ‘X’ is the length of the first stick and ‘Y’ is the length of the second stick and the new stick we get will have a length equal to (X+Y). You have to find the minimum cost to connect all the sticks into one.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:

// 1 <= T <= 10
// 1 <= N <= 10^4
// 1 <= Val <= 5*10^3

// Where ‘T’ represents the number of test cases, ‘N’ represents the number of sticks, and ‘Val’ represents the initial length of any stick.


// Time Limit: 1 sec

// Sample Input 1:

// 2
// 3  
// 2 4 3
// 4
// 1 8 3 5 

// Sample Output 1:

// 14
// 30

// Explanation For Sample Input 1:

// For the first test case, 
// We have sticks of length {2, 4, 3}. First, connect sticks of length 2 and 3 to form a stick of length 5 and which gives a cost of 5. Now we have two sticks of length 5 and 4 each. Now we will connect sticks of length 5 and 4 to form one complete stick of length 9 which gives a cost of 9 and a total cost is 5 + 9 = 14.

// For the second test case, 
// We have sticks of length {1, 8, 3, 5}. First, connect sticks of length 1 and 3 to form a stick of length 4 and which gives a cost of 4. Now we have sticks of length as {4, 8, 5}. Then connect sticks of length 4 and 5 to form a stick of length 9 and it gives a cost of 9. Now we have sticks of length as {9, 8}. Finally, connect the stick of length 8 and 9 which gives a cost of 17 and a total cost is 4 + 9 + 17= 30.

// Sample Input 2:

// 2
// 3
// 2 9 7
// 2
// 10 9

// Sample Output 2:

//  27
//  19
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long int minimumCostToConnectSticks(vector<int> &arr) {

    // Min heap
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    // Insert all sticks
    for (int x : arr) {
        minHeap.push(x);
    }

    long long totalCost = 0;

    // Keep combining 2 smallest
    while (minHeap.size() > 1) {

        long long first = minHeap.top();
        minHeap.pop();

        long long second = minHeap.top();
        minHeap.pop();

        long long cost = first + second;

        totalCost += cost;

        minHeap.push(cost);
    }

    return totalCost;
}