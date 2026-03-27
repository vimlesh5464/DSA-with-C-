// You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:

//     The maximum number of jobs that can be completed within their deadlines.
//     The total maximum profit earned by completing those jobs.

// Examples :

// Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

// Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
// Output: [2, 127]
// Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

// Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
// Output: [3, 100]
// Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

// Constraints:
// 1 ≤ deadline.size() = profit.size() ≤ 105
// 1 ≤ deadline[i] ≤ deadline.size()
// 1 ≤ profit[i] ≤ 500
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        // Step 1: Create jobs as (profit, deadline)
        vector<pair<int,int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Step 2: Sort jobs by profit (descending)
        sort(jobs.begin(), jobs.end(), greater<>());

        // Step 3: Find maximum deadline
        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // Step 4: Slot array
        vector<int> slot(maxDeadline + 1, -1);

        int jobCount = 0;
        int maxProfit = 0;

        // Step 5: Assign jobs
        for(int i = 0; i < n; i++) {
            int currProfit = jobs[i].first;
            int currDeadline = jobs[i].second;

            for(int j = currDeadline; j > 0; j--) {
                if(slot[j] == -1) {
                    slot[j] = 1;
                    jobCount++;
                    maxProfit += currProfit;
                    break;
                }
            }
        }

        return {jobCount, maxProfit};
    }
};

class Solution {
  public:
    // DSU parent
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        // Step 1: Store jobs as (profit, deadline)
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Step 2: Sort by profit descending
        sort(jobs.begin(), jobs.end(), greater<>());

        // Step 3: Find max deadline
        int maxDeadline = 0;
        for (int d : deadline)
            maxDeadline = max(maxDeadline, d);

        // Step 4: Initialize DSU
        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int jobCount = 0, maxProfit = 0;

        // Step 5: Assign jobs using DSU
        for (auto &job : jobs) {
            int currProfit = job.first;
            int currDeadline = job.second;

            int availableSlot = find(currDeadline);

            if (availableSlot > 0) {
                jobCount++;
                maxProfit += currProfit;

                // Mark slot as occupied
                parent[availableSlot] = find(availableSlot - 1);
            }
        }

        return {jobCount, maxProfit};
    }
};
