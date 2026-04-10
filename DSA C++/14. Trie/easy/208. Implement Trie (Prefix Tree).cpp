// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

//     Trie() Initializes the trie object.
//     void insert(String word) Inserts the string word into the trie.
//     boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
//     boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

 

// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True

 

// Constraints:

//     1 <= word.length, prefix.length <= 2000
//     word and prefix consist only of lowercase English letters.
//     At most 3 * 104 calls in total will be made to insert, search, and startsWith.

  
//   /**
//    * Your Trie object will be instantiated and called as such:
//    * Trie* obj = new Trie();
//    * obj->insert(word);
//    * bool param_2 = obj->search(word);
//    * bool param_3 = obj->startsWith(prefix);
//    */

#include <iostream>
#include<string>
using namespace std;

class Trie {
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

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (node->links[ch - 'a'] == NULL) {
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char ch : word) {
            if (node->links[ch - 'a'] == NULL) {
                return false;
            }
            node = node->links[ch - 'a'];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            if (node->links[ch - 'a'] == NULL) {
                return false;
            }
            node = node->links[ch - 'a'];
        }

        return true;
    }
};

int main() {
    Trie trie;

    int q;
    cin >> q;   // number of operations

    while (q--) {
        string op, word;
        cin >> op >> word;

        if (op == "insert") {
            trie.insert(word);
        }
        else if (op == "search") {
            cout << (trie.search(word) ? "true" : "false") << endl;
        }
        else if (op == "startsWith") {
            cout << (trie.startsWith(word) ? "true" : "false") << endl;
        }
    }

    return 0;
}