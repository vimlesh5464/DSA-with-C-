#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue for BFS -> {word, number of steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // Store words in a set for quick lookup
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we found the end word, return the steps
            if (word == endWord)
                return steps;

            // Try changing every character of the word
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);  // mark visited
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // restore
            }
        }

        // No transformation possible
        return 0;
    }
};

int main() {
    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int ans = sol.ladderLength(beginWord, endWord, wordList);

    cout << "Minimum transformations from " << beginWord
         << " to " << endWord << " = " << ans << endl;

    return 0;
}
