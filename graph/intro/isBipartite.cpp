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

  bool isBipartite(int start) {
    queue<int> q;
    vector<int> visited(adj.size() + 1, -1);
    q.push(start);

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (auto edge : adj[node]) {
        if (visited[edge] == -1) {
          visited[edge] = 1 - visited[node];
          q.push(edge);
        } else if (visited[edge] == visited[node]) {
          return false;
        }
      }
    }

    return true;
  }
};

class DFS {
 private:
  int n, m;
  // adjecncy List
  vector<vector<int>> adj;
  vector<int> visited;
  vector<int> color;

 public:
  DFS(int n, int m) {
    this->n = n;
    this->m = m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    color.resize(n + 1, -1);
  }

  void addEdges() {
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

  bool bipatite(int currNode) {
    color[currNode] = 0;
    return solver(currNode);
  }

  bool solver(int currNode) {
    for (auto edge : adj[currNode]) {
      if (color[edge] == -1) {
        color[edge] = !currNode;
        if (solver(edge) == false) return false;

      } else if (color[edge] == color[currNode]) return false;
    } 
    
    return true;
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

  int ans = graph.bipatite(start);

  if (ans) {
    cout << "graph is bipartite\n";
  } else {
    cout << "graph is not bipartite\n";
  }
  return 0;
}