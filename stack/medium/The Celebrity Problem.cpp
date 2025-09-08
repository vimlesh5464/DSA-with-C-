

#include <iostream>
#include <vector>
#include<stack>
using namespace std;
//[Naive Approach] Using Adjacency List - O(n2) Time and O(n) Space

int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();

    // indegree and outdegree array
    vector<int> indegree(n, 0), outdegree(n, 0);

    // query for all edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = mat[i][j];

            // set the degrees
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

    // find a person with indegree n-1
    // and out degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == n && outdegree[i] == 1)
            return i;

    return -1;
}

//[Better Approach] Using Stack - O(n) Time and O(n) Space
int celebrity(vector<vector<int>> & mat) {
  int n = mat.size();
  stack<int> st;

  // push everybody in stack
  for (int i = 0; i < n; i++)
      st.push(i);

  // find a potential celebrity
  while (st.size() > 1) {

      int a = st.top();
      st.pop();

      int b = st.top();
      st.pop();

      // if a knows b
      if (mat[a][b]) {
          st.push(b);
      }
      else {
          st.push(a);
      }
  }

  // potential candidate of celebrity
  int c = st.top();
  st.pop();

  // Check if c is actually
  // a celebrity or not
  for (int i = 0; i < n; i++) {
      if(i == c) continue;

      // if any person doesn't
      // know 'c' or 'c' doesn't
      // know any person, return -1
      if (mat[c][i] || !mat[i][c])
          return -1;
  }

  return c;
}

//[Expected Approach] Using Two Pointers - O(n) Time and O(1) Space
int celebrity(vector<vector<int>> & mat) {
  int n = mat.size();

  int i = 0, j = n - 1;
  while (i < j) {
      
      // j knows i, thus j can't be celebrity
      if (mat[j][i] == 1) 
          j--;

      // else i can't be celebrity
      else
          i++;
  }

  // i points to our celebrity candidate
  int c = i;

  // check if c is actually
  // a celebrity or not
  for (i = 0; i < n; i++) {
      if(i == c) continue;

      // if any person doesn't
      // know 'c' or 'c' doesn't
      // know any person, return -1
      if (mat[c][i] || !mat[i][c])
          return -1;
  }

  return c;
}


int main() {
    vector<vector<int> > mat = {{ 1, 1, 0 },
                                { 0, 1, 0 },
                                { 0, 1, 1 }};
    cout << celebrity(mat);
    return 0;
}