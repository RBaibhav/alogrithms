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
  int n, m;
  cin >> n >> m;
  BFS graph(n, m);
  
  graph.addEdges();

  int start;
  cout << "starting Node : " ;
  cin >> start;

  graph.traverse(start);

  return 0;
}