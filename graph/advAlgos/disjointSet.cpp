#include <bits/stdc++.h>
using namespace std;

class Disjointset {
  vector<int> rank, parent, size;

 public:
  Disjointset(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int findPar(int node) {
    if (node == parent[node]) {
      return node;
    } else {
      return parent[node] = findPar(parent[node]);
    }
  }

  void unionByRank(int u, int v) {
    int ulpr_u = findPar(u);
    int ulpr_v = findPar(v);

    if (ulpr_u == ulpr_v) return;

    if (rank[ulpr_u] < rank[ulpr_v]) {
      parent[ulpr_u] = ulpr_v;
    } else if (rank[ulpr_u] > rank[ulpr_v]) {
      parent[ulpr_v] = ulpr_u;
    } else {
      parent[ulpr_v] = ulpr_u;
      rank[ulpr_v]++;
    }
  }

  void unionBySize(int u, int v) {
    int ulpr_u = findPar(u);
    int ulpr_v = findPar(v);

    if (ulpr_u == ulpr_v) return;

    if (size[ulpr_u] < size[ulpr_v]) {
      size[ulpr_v] += size[ulpr_u];
      parent[ulpr_u] = ulpr_v;
    } else {
      size[ulpr_u] += size[ulpr_v];
      parent[ulpr_v] = ulpr_u;
    }
  }

  bool sameComponet(int u, int v) { return findPar(u) == findPar(v); }
};

int main() {
  Disjointset djs(10);
  djs.unionByRank(1, 2);
  djs.unionByRank(2, 3);
  djs.unionByRank(4, 5);
  djs.unionByRank(6, 7);
  djs.unionByRank(1, 2);
  djs.unionByRank(1, 2);
  djs.unionByRank(1, 2);

  return 0;
}