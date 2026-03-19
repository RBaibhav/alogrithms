#include <bits/stdc++.h>
using namespace std;

int coinChangeRecursive(vector<int>& coins, int amount, int n) {
  if (amount == 0) return 1;
  if (n == 0) return 0;

  if (coins[n - 1] <= amount) {
    return coinChangeRecursive(coins, amount - coins[n - 1], n) +
           coinChangeRecursive(coins, amount, n - 1);
  } else {
    return coinChangeRecursive(coins, amount, n - 1);
  }
}

int coinChnageIDP(vector<int>& coins, int amount) {
  vector<vector<int>> t(coins.size() + 1, vector<int>(amount + 1, 0));

  for (int i = 1; i <= coins.size(); i++) {
    t[i][0] = 1;
  }

  for (int i = 1; i <= coins.size(); i++) {
    for (int j = 1; j <= amount; j++) {
      if (coins[i - 1] <= j) {
        t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
      } else {
        t[i][j] = t[i - 1][j];
      }
    }
  }

  return t[coins.size()][amount];
}

int calculateTheMinimumCoins(vector<int>& coins, int amount, int n) {
  if (amount == 0) return 0;
  if (n == 0) return INT_MAX - 1;

  if (coins[n - 1] <= amount) {
    return min(1 + calculateTheMinimumCoins(coins, amount - coins[n - 1], n),
               calculateTheMinimumCoins(coins, amount, n - 1));
  } else {
    return calculateTheMinimumCoins(coins, amount, n - 1);
  }
}

int calculateTheMinimumCoinsDP(vector<int> &coins, int amount) {
  vector<vector<int>> t(coins.size() + 1, vector<int>(amount + 1, -1));
  
  for (int i = 1; i <= coins.size(); i++) t[i][0] = 0;
  for (int j = 0; j <= amount; j++) t[0][j] = INT_MIN - 1;

  for (int i = 1; i <= coins.size(); i++) {
    for (int j = 1; j <= amount; j++) {
      if (coins[i - 1] <= j) {
        t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
      } else {
        t[i][j] = t[i - 1][j];
      }
    }
  }
  

  return t[coins.size()][amount];
  
}

int main() {
  vector<int> coins = {1, 2, 3};
  int amount = 9;
  // find the total number of ways the coins can be selected so that sum is 5,
  // coins are unlimited

  int ans = coinChangeRecursive(coins, amount, coins.size());

  cout << ans << endl;
  ans = coinChnageIDP(coins, amount);
  cout << ans << endl;

  ans = calculateTheMinimumCoinsDP(coins, amount);
  cout << ans << endl;
  return 0;
}