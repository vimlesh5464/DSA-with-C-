#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int N) {
    // Min-heap storing {value, original_index}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    for(int i = 0; i < N; i++)
        pq.push({arr[i], i});

    vector<int> ans(N);
    int rank = 1;
    int prevVal = INT_MIN;

    while(!pq.empty()) {
        auto [val, idx] = pq.top();
        pq.pop();

        if(val != prevVal) {
            prevVal = val;
        }

        ans[idx] = rank;

        // Increment rank if next element is different
        if(!pq.empty() && pq.top().first != val)
            rank++;
    }

    return ans;
}

int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter elements: ";
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> rankedArr = replaceWithRank(arr, N);

    cout << "Array after replacing with ranks: ";
    for(int x : rankedArr)
        cout << x << " ";
    cout << endl;

    return 0;
}
