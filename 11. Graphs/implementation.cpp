#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
// class Graph{
//   int V;
//   list<int> *l;
//   public:
//   Graph(int V){
//     this->V=V;
//     l = new list<int> [V];
//     // int *arr;
//     // arr=new int[V];
//   }
//   void EdgeList(int u, int v){
//     l[u].push_back(v);
//     l[v].push_back(u);
//   }
//   void print(){
//     for(int u=0; u < V; u++){
//       list<int> neighbor = l[u];
//       cout<<u<<" : ";
//       for(int v : neighbor){
//         cout << v << " ";
//     }
    
//       cout<<endl;
//     }
//   }
// };
class Graph{
  int V;                                  // Number of vertices
  list<pair<int,int>> *l;                 // Adjacency list (node, weight)

public:
  Graph(int V){
      this->V = V;                        // Store number of vertices
      l = new list<pair<int,int>>[V];     // Create array of lists for adjacency list
  }

  // Function to add an undirected weighted edge
  void EdgeList(int u, int v, int w){
      l[u].push_back({v, w});             // Add (neighbor, weight) to u
      l[v].push_back({u, w});             // Add (neighbor, weight) to v (because undirected)
  }

  // Function to print adjacency list
  void print(){
      for(int u = 0; u < V; u++){
          list<pair<int,int>> neighbor = l[u];  // Get neighbor list for node u
          cout << u << " : ";

          for(auto v : neighbor){
              // v.first  = neighbor node
              // v.second = weight of the edge
              cout << "(" << v.first << ", " << v.second << ") ";
          }

          cout << endl;
      }
  }
};
