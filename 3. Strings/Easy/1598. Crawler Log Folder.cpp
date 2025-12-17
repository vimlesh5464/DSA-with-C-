#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for (string log : logs) {
            if (log == "../") {
                if (depth > 0) depth--;
            }
            else if (log == "./") {
                continue;
            }
            else {
                depth++;
            }
        }
        return depth;
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;

    vector<string> logs(n);
    for (int i = 0; i < n; i++) {
        cin >> logs[i];
    }

    cout << obj.minOperations(logs);
    return 0;
}
