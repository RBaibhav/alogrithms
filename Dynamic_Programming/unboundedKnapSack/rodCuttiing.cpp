#include <bits/stdc++.h>
using namespace std;

int unboundedKnapSack(vector<int> &len, vector<int> &price, int l, int n) {
  if (l == 0 || n == 0) return 0;

  if (len[n - 1] <= l) {
    return max(price[n - 1] + unboundedKnapSack(len, price, l - len[n - 1], n), unboundedKnapSack(len, price, l, n - 1));
  } else {
    return unboundedKnapSack(len, price, l, n - 1);
  }

}

int main() {
  vector<int> len = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
  int n = 8;

  int ans = unboundedKnapSack(len, price, n, len.size());
  
  cout << ans << endl;

  return 0;
}
