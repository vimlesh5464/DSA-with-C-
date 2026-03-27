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