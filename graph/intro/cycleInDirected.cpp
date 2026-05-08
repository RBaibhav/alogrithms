#include <bits/stdc++.h>
using namespace std;

class DFS {
 private:
  int n, m;
  // adjecncy List
  vector<vector<int>> adj;
  vector<int> visited;
  vector<int> pathVisited;

 public:
  DFS(int n, int m) {
    this->n = n;
    this->m = m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    pathVisited.resize(n + 1, 0);
  }

  void addEdges() {
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
  }

  // for diercted go component wise too 
  void traverse(int node) {
    visited[node] = 1;
    cout << node << "  ";

    for (auto edge : adj[node]) {
      if (visited[edge] == 0) {
        traverse(edge);
      }
    }
  }

  bool isCycle(int start) {
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        if (cycleSolver(i)) {
          return true;
        }
      }
    }

    return false;
  }

  bool cycleSolver(int node) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for (auto edge : adj[node]) {
      if (!visited[edge]) {
        if (cycleSolver(edge)) return true;
      } else if (visited[edge] && pathVisited[edge])
        return true;
    }

    pathVisited[node] = false;
    return false;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  DFS graph(n, m);

  graph.addEdges();

  int start;
  cout << "starting Node : ";
  cin >> start;

  graph.traverse(start);

  int ans = graph.isCycle(start);

  if (ans) {
    cout << "there is a cycle\n";
  } else {
    cout << "there is not a cycle\n";
  }

  return 0;
}