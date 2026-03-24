#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the minimal subsequence that forms a majority
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;          // To store the resulting subsequence
        int total = 0;            // Total sum of all votes
        int n = nums.size();      // Number of students/votes
        
        // Step 1: Calculate total sum of votes
        for(int i = 0; i < n; i++)
            total += nums[i];
        
        // Step 2: Sort votes in descending order
        // Picking largest votes first ensures minimal size subsequence
        sort(nums.begin(), nums.end(), greater<int>());
        
        int val = 0; // Sum of currently selected votes
        // Step 3: Pick votes until majority is formed
        for(int i = 0; i < n; i++) {
            val += nums[i];          // Add current vote to subsequence sum
            ans.push_back(nums[i]);  // Add current vote to answer vector
            if(val > total - val)    // Check if selected votes > remaining votes
                break;               // Stop once majority is formed
        }
        
        // Step 4: Return the subsequence in non-increasing order
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;                 // Input the number of votes/students
    vector<int> votes(n);
    
    // Input votes for each student
    for(int i = 0; i < n; i++) {
        cin >> votes[i];
    }  
    
    // Get the minimal subsequence forming majority
    vector<int> subseq = s.minSubsequence(votes);
    
    // Print the result
    for(int i = 0; i < subseq.size(); i++) {
        cout << subseq[i] << " ";
    }
    cout << endl;

    return 0;
}