#include <bits/stdc++.h>
using namespace std;

class DFS {
 private:
  int n, m;
  // adjecncy List
  vector<vector<int>> adj;
  vector<int> visited;

 public:
  DFS(int n, int m) {
    this->n = n;
    this->m = m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
  }

  void fill() {
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  void traverse(int node) {
    visited[node] = 1;
    cout << node << "  ";

    for (auto edge : adj[node]) {
      if (visited[edge] == 0) {
        traverse(edge);
      }
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  DFS graph(n, m);
  graph.fill();

  int startNode;
  cout << "Starting Node : ";
  cin >> startNode;

  graph.traverse(startNode);
  cout << "\n";

  return 0;
}