#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        int n = start.size();
        
        // Store meetings as (end_time, start_time)
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Sort meetings by end time
        sort(meetings.begin(), meetings.end());

        int count = 0;
        int lastEnd = -1;

        // Greedy selection
        for (auto &m : meetings) {
            int e = m.first;
            int s = m.second;

            if (s > lastEnd) {
                count++;
                lastEnd = e;
            }
        }

        return count;
    }
};
