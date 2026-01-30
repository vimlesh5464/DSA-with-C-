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
