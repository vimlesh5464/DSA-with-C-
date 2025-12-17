#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        queue<char> q1, q2;

        // push characters into queues
        for (char c : s) q1.push(c);
        for (char c : goal) q2.push(c);

        int n = s.length();

        for (int i = 0; i < n; i++) {
            // rotate q1
            char front = q1.front();
            q1.pop();
            q1.push(front);

            // compare q1 and q2
            if (areEqual(q1, q2))
                return true;
        }
        return false;
    }

    bool areEqual(queue<char> a, queue<char> b) {
        while (!a.empty()) {
            if (a.front() != b.front())
                return false;
            a.pop();
            b.pop();
        }
        return true;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        queue<char> q;
        for (char c : s) q.push(c);

        int n = s.length();
        for (int i = 0; i < n; i++) {
            // rotate
            char front = q.front();
            q.pop();
            q.push(front);

            // build string from queue
            string rotated = "";
            queue<char> temp = q;
            while (!temp.empty()) {
                rotated += temp.front();
                temp.pop();
            }

            if (rotated == goal) return true;
        }
        return false;
    }
};

int main() {
    Solution obj;
    string s, goal;

    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter goal string: ";
    cin >> goal;

    if (obj.rotateString(s, goal))
        cout << "True (Rotation possible)" << endl;
    else
        cout << "False (Rotation not possible)" << endl;

    return 0;
}
