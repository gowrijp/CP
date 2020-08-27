/*
https://codeforces.com/problemset/problem/913/C

A New Year party is not a New Year party without lemonade! As usual, you are expecting a lot of guests, and buying lemonade has already become a pleasant necessity.

Your favorite store sells lemonade in bottles of n different volumes at different costs. A single bottle of type i has volume 2^(i-1) liters and costs ci roubles. The number of bottles of each type in the store can be considered infinite.

You want to buy at least L liters of lemonade. How many roubles do you have to spend?

SOLUTION: https://codeforces.com/blog/entry/56992
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, L;
  scanf("%d %d", &n, &L);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    c[i + 1] = min(c[i + 1], 2 * c[i]);
  }
  long long ans = (long long) 4e18;
  long long sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    int need = L / (1 << i);
    sum += (long long) need * c[i];
    L -= need << i;
    ans = min(ans, sum + (L > 0) * c[i]);
  }
  cout << ans << endl;
  return 0;
}
