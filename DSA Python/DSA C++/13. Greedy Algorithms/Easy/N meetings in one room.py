# N meetings in one room.py - Python skeleton converted from C++

# Original C++ code:
# // You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 
# 
# // Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
# 
# // Examples :
# 
# // Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
# // Output: 4
# // Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
# 
# // Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
# // Output: 1
# // Explanation: Only one meetings can be held with given start and end timings.
# 
# // Input: start[] = [1, 2], end[] = [100, 99]
# // Output: 1
# 
# // Constraints:
# // 1 ≤ n ≤ 105
# //0 ≤ start[i] < end[i] ≤ 10^6
# #include <iostream>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#     // Function to find the maximum number of meetings that can
#     // be performed in a meeting room.
#     int maxMeetings(vector<int>& start, vector<int>& end) {
#         
#         int n = start.size();
#         
#         // Store meetings as (end_time, start_time)
#         vector<pair<int, int>> meetings;
#         for (int i = 0; i < n; i++) {
#             meetings.push_back({end[i], start[i]});
#         }
# 
#         // Sort meetings by end time
#         sort(meetings.begin(), meetings.end());
# 
#         int count = 0;
#         int lastEnd = -1;
# 
#         // Greedy selection
#         for (auto &m : meetings) {
#             int e = m.first;
#             int s = m.second;
# 
#             if (s > lastEnd) {
#                 count++;
#                 lastEnd = e;
#             }
#         }
# 
#         return count;
#     }
# };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
