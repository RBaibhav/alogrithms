#include <bits/stdc++.h>
using namespace std;

int solver(vector<int>& mat, int i, int j, vector<vector<int>>& t) {
  if (i == j) return 0;

  if (t[i][j] != -1) return t[i][j];

  int ans = INT_MAX;
  for (int k = i; k < j; k++) {
    int temp = solver(mat, i, k, t) + solver(mat, k + 1, j, t) +
               mat[i - 1] * mat[k] * mat[j];
    ans = min(ans, temp);
  }
  return t[i][j] = ans;
}

int mcmTabular(vector<int>& mat) {
  int i = 1, j = mat.size() - 1;
  vector<vector<int>> t(mat.size(), vector<int>(mat.size(), 0));
  int n = mat.size();
  for (int i = 1; i < n; i++) {
    t[i][i] = 0;
  }
  
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int ans = INT_MAX;
      for (int k = i; k < j; k++) {
        int temp = t[i][k] + t[k + 1][j] + mat[i - 1] * mat[k] * mat[j];
        ans = min(ans, temp);
      }

      t[i][j] = ans;
    }
  }

  return t[1][n - 1];
}

int main() {
  vector<int> mat = {40, 20, 30, 10, 30};
  vector<vector<int>> t(mat.size() + 1, vector<int>(mat.size() + 1, -1));
  cout << mcmTabular(mat) << endl;
  return 0;
}