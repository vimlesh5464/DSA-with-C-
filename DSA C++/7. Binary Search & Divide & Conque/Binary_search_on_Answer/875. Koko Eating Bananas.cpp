// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

 

// Constraints:

//     1 <= piles.length <= 104
//     piles.length <= h <= 109
//     1 <= piles[i] <= 109

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMax(const vector<int> &v) {
        int mx = v[0];
        for (int x : v) mx = max(mx, x);
        return mx;
    }

    long long calculateTotalHours(const vector<int> &v, long long hourly) {
        long long totalH = 0;
        for (int x : v) {
            totalH += (x + hourly - 1) / hourly; // integer ceil
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = findMax(piles);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= (long long)h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};

int main(){
  Solution s;
  int n;
  cin>>n;
  cout<<n;
  vector<int> piles(n);
  for(int i = 0; i < n; i++){
    cin>> piles[i];
  }
  int h;
  cin>>h;
  cout<<h<<endl;
  
  
  cout<<"koko Earing Bananas"<<s.minEatingSpeed(piles,h);
  return 0;
}