#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j) {
  bool ans = true;

  int l = i, r = j;
  while (l < r) {
    if (s[l] != s[r]) {
      ans = false;
    }
    l++, r--;
  }

  return ans;
}

int solver(string s, int i, int j, vector<vector<int>>& t) {
  if (t[i][j] != -1) return t[i][j];
  if (i == j) return 0;
  if (isPalindrome(s, i, j)) return 0;

  int ans = INT_MAX;
  for (int k = i; k < j; k++) {
    int temp = solver(s, i, k, t) + solver(s, k + 1, j, t) + 1;
    ans = min(temp, ans);
  }

  return t[i][j] = ans;
}

int main() {
  string s = "ababc";

  vector<vector<int>> t(s.size() + 1, vector<int>(s.size(), -1));
  cout << solver(s, 0, s.length() - 1, t) << endl;
  return 0;
}