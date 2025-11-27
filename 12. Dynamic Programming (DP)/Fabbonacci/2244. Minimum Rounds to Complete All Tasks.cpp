#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;

        for (int t : tasks) {
            freq[t]++;
        }

        int rounds = 0;

        for (auto &it : freq) {
            int f = it.second;

            if (f == 1) return -1;

            rounds += (f + 2) / 3;
        }

        return rounds;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<int> tasks(n);
    cout << "Enter tasks: ";
    for (int i = 0; i < n; i++)
        cin >> tasks[i];

    cout << "Minimum Rounds = " << s.minimumRounds(tasks) << endl;

    return 0;
}
