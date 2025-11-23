#include<iostream>
#include<vector>
using namespace std;

void dfs(string &str, int index, string curr, int count, vector<string> &ans) {

    if (index == str.size()) {
        if (count > 0) curr += to_string(count);
        ans.push_back(curr);
        return;
    }

    dfs(str, index + 1, curr, count + 1, ans);

    if (count > 0) curr += to_string(count);
    dfs(str, index + 1, curr + str[index], 0, ans);
}

vector<string> findAbbr(string &str) {
    vector<string> ans;
    dfs(str, 0, "", 0, ans);

    // ⭐ Important: Sort lexicographically to match expected output:
    sort(ans.begin(), ans.end());

    return ans;
}
