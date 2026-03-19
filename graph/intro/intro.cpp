#include <bits/stdc++.h>
using namespace std;

class BFS {
 private:
  int n, m;
  vector<vector<int>> adj;

 public:
  BFS(int nodes, int edges) {
    n = nodes;
    m = edges;
    adj.resize(n + 1);
  }

  void addEdges() {
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  void traverse(int start) {
    vector<int> visited(n + 1, 0);

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
      int temp = q.front();
      q.pop();

      if (visited[temp] == 0) {
        cout << temp << "  ";
        visited[temp] = 1; 
      }
      
      for (int i = 0; i < adj[temp].size(); i++) {
        int nodeFromTemp = adj[temp][i];
        if (visited[nodeFromTemp] == 0) {
          q.push(nodeFromTemp);
        }
      }
    }
  }
};

int main() {
  /*
   how to store a graph
   I/P : n, m (no of nodes, no of edges)
   realtion m relation
   1 2
   2 4
   4 3
   1 5
   5 3


   how to store ?
      1. Matrix
      2. List way


      make a 2D matrix of size N * N and mark mat[i][j] = 1

  */

  int n, m;  // n => no. of nodes, m => no. of edges
  cin >> n >> m;

  // matrix implemntation
  // for weighted graph just put the weight instead of 1
  int mat[n + 1][n + 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    mat[u][v] = 1;
    mat[v][u] = 1;
  }

  // List way
  // for weighted graph just put the weight as the 3rd param like node1 => node2
  // with weight w
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return 0;
}