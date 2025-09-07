#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int num : nums) freq[num]++;

    vector<pair<int,int>> v;
    for(auto &p : freq) {
        v.push_back({p.first, p.second});
    }

    // Custom sort: higher frequency first, if same frequency larger element first
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });

    vector<int> ans;
    for(int i=0; i<k; i++) {
        ans.push_back(v[i].first);
    }
    return ans;
}

int main() {
    int N = 8;
    vector<int> nums = {1,1,2,2,3,3,3,4};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    for(int x : result) cout << x << " ";
    return 0;
}
