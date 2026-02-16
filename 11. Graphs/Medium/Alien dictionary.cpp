#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Solution {
  public:

  vector<int> topoSort(int V, vector<int> adj[])
  {
      vector<int> indegree(V,0);

      for (int i = 0; i < V; i++) {
          for (auto it : adj[i]) {
              indegree[it]++;
          }
      }

      queue<int> q;
      for (int i = 0; i < V; i++) {
          if (indegree[i] == 0) {
              q.push(i);
          }
      }

      vector<int> topo;
      while (!q.empty()) {
          int node = q.front();
          q.pop();
          topo.push_back(node);

          for (auto it : adj[node]) {
              indegree[it]--;
              if (indegree[it] == 0) 
                  q.push(it);
          }
      }

      return topo;
  }

  string findOrder(vector<string> &words) {

      vector<int> adj[26];
      vector<int> present(26,0);

      // mark present characters
      for(auto word : words){
          for(auto ch : word){
              present[ch - 'a'] = 1;
          }
      }

      for (int i = 0; i < words.size() - 1; i++) {

          string s1 = words[i];
          string s2 = words[i + 1];

          int len = min(s1.size(), s2.size());

          bool found = false;

          for (int ptr = 0; ptr < len; ptr++) {
              if (s1[ptr] != s2[ptr]) {
                  adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                  found = true;
                  break;
              }
          }

          // invalid case: prefix problem
          if(!found && s1.size() > s2.size())
              return "";
      }

      vector<int> topo = topoSort(26, adj);

      string ans = "";

      for (auto it : topo) {
          if(present[it])
              ans += char(it + 'a');
      }

      // count unique chars
      int unique = 0;
      for(int i = 0; i < 26; i++)
          if(present[i]) unique++;

      // cycle check
      if(ans.size() != unique)
          return "";

      return ans;
  }
};
class Solution {
	// works for multiple components
private:
	vector<int> topoSort(int V, vector<int> adj[])
	{
    vector<int> indegree(V,0);
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
public:
	string findOrder(string dict[], int N, int K) {
		vector<int>adj[K];
		for (int i = 0; i < N - 1; i++) {
			string s1 = dict[i];
			string s2 = dict[i + 1];
			int len = min(s1.size(), s2.size());
			for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
					adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
					break;
				}
			}
		}

		vector<int> topo = topoSort(K, adj);
		string ans = "";
		for (auto it : topo) {
			ans = ans + char(it + 'a');
		}
		return ans;
	}
};

int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}

