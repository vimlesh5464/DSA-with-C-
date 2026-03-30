// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 

// Constraints:

//     1 <= numCourses <= 2000
//     0 <= prerequisites.length <= 5000
//     prerequisites[i].length == 2
//     0 <= ai, bi < numCourses
//     All the pairs prerequisites[i] are unique.
#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Solution {
  public:
      // helper returns true if a cycle is detected
       bool dfsCycleHelper(int src, vector<vector<int>> &adj,
                          vector<bool>& vis, vector<bool>& recPath) {
  
          vis[src] = true;
          recPath[src] = true;
  
          for (int v : adj[src]) {
  
              if (!vis[v]) {
                  if (dfsCycleHelper(v, adj, vis, recPath))
                      return true;
              }
              else if (recPath[v]) {
                  return true;
              }
          }
  
          recPath[src] = false;
          return false;
      }
  
      bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          // build adjacency list
          vector<vector<int>> adj(numCourses);
          for(auto &edge : prerequisites) {
              int course = edge[0], prereq = edge[1];
              adj[prereq].push_back(course); // prereq -> course
          }
          vector<bool> vis(numCourses, false);
          vector<bool> recPath(numCourses, false);
          
          for(int i = 0; i < numCourses; i++) {
              if(vis[i] == false) {
                  if(dfsCycleHelper(i, adj, vis, recPath)) return false; // cycle detected
              }
          }
          return true; // no cycle found
      }
  };
  