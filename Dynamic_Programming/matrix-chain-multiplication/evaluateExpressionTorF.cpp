#include <bits/stdc++.h>
using namespace std;

bool evaluate(bool left, bool right, char op) {
  if (op == '|') return left | right;
  if (op == '&') return left & right;

  return left ^ right;
}

int solver(string s, int i, int j, int isTrue , vector<vector<vector<int>>> &memo) {
  if (i == j) {
    return (isTrue == (s[i] == 'T')) ? 1 : 0;
  }
  
  if (memo[i][j][isTrue] != -1) return memo[i][j][isTrue];

  int ways = 0;
  for (int k = i + 1; k < j; k += 2) {
    int leftTrue = solver(s, i, k - 1, true, memo);
    int leftFalse = solver(s, i, k - 1, false, memo);

    int rightTrue = solver(s, k + 1, j, true, memo);
    int rightFalse = solver(s, k + 1, j, false, memo);

    if (evaluate(true, true, s[k]) == isTrue) {
      ways += leftTrue * rightTrue;
    }
    if (evaluate(true, false, s[k]) == isTrue) {
      ways += leftTrue * rightFalse;
    }
    if (evaluate(false, true, s[k]) == isTrue) {
      ways += leftFalse * rightTrue;
    }
    if (evaluate(false, false, s[k]) == isTrue) {
      ways += leftFalse * rightFalse;
    }
  }

  return memo[i][j][isTrue] = ways;
}

int main() {
  string s = "T|T&F^T";  // put brackets such that the expression can be
                         // evaluated to true => return number of ways you can
                         // put parenthesis such that it will evaluate to true

  int n = s.length();
  vector<vector<vector<int>>> memo(
      n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
  cout << solver(s, 0, s.length() - 1, true, memo) << endl;
  return 0;
}