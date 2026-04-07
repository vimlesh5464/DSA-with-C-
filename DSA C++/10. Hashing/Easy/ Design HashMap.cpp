// Bob, in a fit of anger, vowed to avoid using built-in libraries after an argument with a programming language developer. He's attempting to create his own functions and data structures but got stuck while implementing a HashMap to map unique integer keys to integer values.
// He needs help to perform three basic operations:

// 1. Insert: Add or update a (key, value) pair.
// 2. Get: Print the value for a given key, or -1 if the key doesn't exist.
// 3. Delete: Remove a key and its corresponding value if present.

// Let's assist Bob in building his own HashMap without relying on any pre-existing hash table libraries.

// Input Format

// The first line of the input contains N, the number of queries.
// Each of the next n lines starts with integer T, the type of query.
// For type = 1, the line further contains 2 integers denoting the key and its corresponding value to be inserted.
// For type = 2, the line further contains a single integer denoting the key whose value is to be printed.
// For type = 3, the line further contains a single integer denoting the key that is to be deleted.

// Output Format

// For queries of type 2, print a single integer – value corresponding to the given key.

// Constraints

// 1 <= N <= 104
// 0 <= key, value <= 10^6
// All the queries are orderly dependent.
// There will be at least one type 2 query.
// In type 3 queries, it is guaranteed that the key given is present in the map at the moment.

// Sample Testcase 0

// Testcase Input
// 8
// 1 1 1
// 1 2 2
// 2 1
// 2 3
// 1 2 1
// 2 2
// 3 2
// 2 2
// Testcase Output
// 1
// -1
// 1
// -1
// Explanation

// For query 1, we insert (1, 1). Our map is now [(1, 1)]
// For query 2, we insert (2, 2). Our map is now [(1, 1), (2, 2)]
// For query 3, we print value corresponding to key 1, i.e., 1
// For query 4, we do not have the key 3 in our map, hence we print -1
// For query 5, we update the value corresponding to key 2 to 1. Out map now is [(1, 1), (2, 1)]
// For query 6, we print the value corresponding to key 2, i.e., 1
// For query 7, we delete the key 2 from the map. Out map now is [(1, 1)]
// For query 8. we do not have the key 2 in our map anymore, hence we print -1
// Sample Testcase 1

// Testcase Input
// 9
// 1 4 2
// 1 25 6
// 2 4
// 1 4 8
// 2 25
// 3 25
// 2 25
// 1 25 1
// 2 25
// Testcase Output
// 2
// 6
// -1
// 1
// Explanation

// For query 1, we insert (4, 2). Our map is now [(4, 2)]
// For query 2, we insert (25, 6). Our map is now [(4, 2), (25, 6)]
// For query 3, we print value corresponding to key 4, i.e., 2
// For query 4, we update the value corresponding to key 4 to 8. Out map now is [(4, 8), (25, 6)]
// For query 5, we print the value corresponding to key 25, i.e., 6
// For query 6, we delete the key 25 from the map. Out map now is [(4, 8)]
// For query 7, we do not have the key 25 in our map anymore, hence we print -1
// For query 8. we insert (25, 1). Our map is now [(4, 8), (25, 1)]
// For query 9, we print the value corresponding to key 25, i.e., 1

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<int> processQueries(vector<tuple<int, int, int>> queries) {
    
    const int SIZE = 10007; // hash table size
    
    // Node structure
    struct Node {
        int key, value;
        Node* next;
        Node(int k, int v) {
            key = k;
            value = v;
            next = NULL;
        }
    };
    
    // Hash table
    vector<Node*> table(SIZE, NULL);
    
    // Hash function
    auto hashFunction = [&](int key) {
        return key % SIZE;
    };
    
    vector<int> result;

    for (auto &q : queries) {
        int type = get<0>(q);
        
        if (type == 1) {
            int key = get<1>(q);
            int value = get<2>(q);
            
            int index = hashFunction(key);
            Node* temp = table[index];
            
            // Check if key exists → update
            while (temp) {
                if (temp->key == key) {
                    temp->value = value;
                    goto next_query;
                }
                temp = temp->next;
            }
            
            // Insert new node at head
            {
                Node* newNode = new Node(key, value);
                newNode->next = table[index];
                table[index] = newNode;
            }
        }
        
        else if (type == 2) {
            int key = get<1>(q);
            
            int index = hashFunction(key);
            Node* temp = table[index];
            
            int ans = -1;
            while (temp) {
                if (temp->key == key) {
                    ans = temp->value;
                    break;
                }
                temp = temp->next;
            }
            
            result.push_back(ans);
        }
        
        else if (type == 3) {
            int key = get<1>(q);
            
            int index = hashFunction(key);
            Node* temp = table[index];
            Node* prev = NULL;
            
            while (temp) {
                if (temp->key == key) {
                    if (prev) {
                        prev->next = temp->next;
                    } else {
                        table[index] = temp->next;
                    }
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
        
        next_query: ;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> queries;
    for (int i = 0; i < n; ++i) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int key, value;
            cin >> key >> value;
            queries.emplace_back(1, key, value);
        } else if (queryType == 2) {
            int key;
            cin >> key;
            queries.emplace_back(2, key, 0);
        } else if (queryType == 3) {
            int key;
            cin >> key;
            queries.emplace_back(3, key, 0);
        }
    }
    vector<int> results = processQueries(queries);
    for (int result : results) {
        cout << result << endl;
    }
    return 0;
}