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

  bool detectCycle(int start) {
    vector<int> visited(n + 1, 0);
    queue<pair<int, int>> q;

    q.push({start, -1});

    while (!q.empty()) {
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();

      if (visited[node] == 0) {
        visited[node] = 1;
      }

      for (int i = 0; i < adj[node].size(); i++) {
        int edgeFromTemp = adj[node][i];
        if (visited[edgeFromTemp] == 0) {
          q.push({edgeFromTemp, node});
        } else if (edgeFromTemp != parent) {
          return true;
        }
      }
    }

    return false;
  }
};

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

  bool detectCycle(int start) { return detectCycleSolver(start, -1); }

  bool detectCycleSolver(int node, int parentNode) {
    visited[node] = 1;

    for (auto edge : adj[node]) {
      if (visited[edge] == 0) {
        if (detectCycleSolver(edge, node) == true) return true;
      } else if (edge != parentNode) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  DFS graph(n, m);

  graph.fill();

  cout << "starting Node : ";
  int start;
  cin >> start;
  bool ans = graph.detectCycle(start);
  if (ans) {
    cout << "true \n";
  } else {
    cout << "false \n";
  }

  return 0;
}