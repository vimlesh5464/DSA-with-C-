
#include <iostream>
#include<string>
using namespace std;
class WordDictionary {
private:
    struct Node {
        Node* links[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) links[i] = NULL;
            isEnd = false;
        }
    };

    Node* root;

    bool dfs(Node* node, string &word, int index) {
        if (!node) return false;

        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        // Case 1: wildcard '.'
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && dfs(node->links[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }

        // Case 2: normal character
        if (node->links[ch - 'a'] == NULL) return false;

        return dfs(node->links[ch - 'a'], word, index + 1);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->links[ch - 'a']) {
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};

int main() {
    WordDictionary wd;

    int q;
    cin >> q;

    while (q--) {
        string op, word;
        cin >> op >> word;

        if (op == "add") {
            wd.addWord(word);
        }
        else if (op == "search") {
            cout << (wd.search(word) ? "true" : "false") << endl;
        }
    }

    return 0;
}