// Given n machines represented by an integer array arr[], where arr[i] denotes the time (in seconds) taken by the i-th machine to produce one item. All machines work simultaneously and continuously. Additionally, we are also given an integer m, representing the total number of items required. The task is to determine the minimum time needed to produce exactly m items efficiently.

// Examples: 

//     Input: arr[] = [2, 4, 5], m = 7
//     Output: 8
//     Explanation: The optimal way to produce 7 items in the minimum time is 8 seconds. Each machine produces items at different rates:

//         Machine 1 produces an item every 2 seconds → Produces 8/2 = 4 items in 8 seconds.
//         Machine 2 produces an item every 4 seconds → Produces 8/4 = 2 items in 8 seconds.
//         Machine 3 produces an item every 5 seconds → Produces 8/5 = 1 item in 8 seconds.

//     Total items produced in 8 seconds = 4 + 2 + 1 = 7


//     Input: arr[] = [2, 3, 5, 7], m = 10
//     Output: 9
//     Explanation: The optimal way to produce 10 items in the minimum time is 9 seconds. Each machine produces items at different rates:

//         Machine 1 produces an item every 2 seconds - Produces 9/2 = 4 items in 9 seconds.
//         Machine 2 produces an item every 3 seconds - Produces 9/3 = 3 items in 9 seconds.
//         Machine 3 produces an item every 5 seconds - Produces 9/5 = 1 item in 9 seconds.
//         Machine 4 produces an item every 7 seconds - Produces 9/7 = 1 item in 9 seconds.

//     Total items produced in 9 seconds = 4 + 3 + 1 + 1 = 10

// JavaScript program to find minimum time 
// required to produce m items using 
// Brute Force Approach
#include<iostream>
#include <cmath>
using namespace std;



int minTimeReq(vector<int> &arr, int m) {
    
    // Start checking from time = 1
    int time = 1;
    
    while (true) {
        int totalItems = 0;

        // Calculate total items produced at 
        // current time
        for (int i = 0; i < arr.size(); i++) {
            totalItems += time / arr[i];
        }

        // If we produce at least m items, 
        // return the time
        if (totalItems >= m) {
            return time;
        }

        // Otherwise, increment time and 
        // continue checking
        time++;
    }
}

int main() {

    vector<int> arr = {2, 4, 5};
    int m = 7;

    cout << minTimeReq(arr, m) << endl;

    return 0;
}



int minTimeReq(vector<int> &arr, int m) {
    
    // Find the minimum value in arr manually
    int minMachineTime = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < minMachineTime) {
            minMachineTime = arr[i];
        }
    }

    // Define the search space
    int left = 1;
    int right = m * minMachineTime;
    int ans = right;
    
    while (left <= right) {
        
        // Calculate mid time
        int mid = left + (right - left) / 2;
        int totalItems = 0;

        // Calculate total items produced in 'mid' time
        for (int i = 0; i < arr.size(); i++) {
            totalItems += mid / arr[i];
        }

        // If we can produce at least m items,
        // update answer
        if (totalItems >= m) {
            ans = mid;
            
            // Search for smaller time
            right = mid - 1;
        } 
        else {
            
            // Search in right half
            left = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    
    vector<int> arr = {2, 4, 5};
    int m = 7;

    cout << minTimeReq(arr, m) << endl;

    return 0;
}