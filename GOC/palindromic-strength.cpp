/*
https://www.hackerrank.com/contests/goc-cdc-series-8/challenges/palindromic-strength

The Palindromic Strength of a String is defined as largest possible product of length of two non-overlapping palindromic Substring of the String.
Input Format

First Line denotes the number of test cases.
First and Only line of each test case denotes the String.
Constraints

1 <= T <= 20
2 <= |S| <= 2000. |S| is length of String.

Output Format

For each Test Case output the Palindromic Strength of the String.

Sample Input 0
1
ab
Sample Output 0

1
Explanation 0

The only two non-overlapping Palindromes are 'a' and 'b'. Product = 1.

Sample Input 1

1
abbabba
Sample Output 1

8
Explanation 1

['abba', 'bb']


SOLUTION
Maintain a DP[i][j] boolean. True if S[i..j] is a palindrome and False otherwise. Use the Table to get the answer. startAt[i] will denote max palindrome starting from i. endAt[i] will denote max palindrome ending at i. The calculations of the same are given in the code.

*/

#include <bits/stdc++.h>
using namespace std;

#define IOS                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);                      \
  cin.exceptions(cin.failbit);

void pre() {}

vector<vector<bool>> dp;
string s;

void solve() {
  cin >> s;
  int n = s.length();
  dp.assign(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++)
    dp[i][i] = true;
  for (int i = 0; i < (n - 1); i++)
    if (s[i] == s[i + 1])
      dp[i][i + 1] = true;
  int t1;
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n; i++) {
      t1 = i + len - 1;
      if (t1 >= n)
        break;
      if (dp[i + 1][t1 - 1]) {
        if (s[i] == s[t1]) {
          dp[i][t1] = true;
        }
      }
    }
  }

  vector<int> endAt(n, 0);
  vector<int> startAt(n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = (i); j < n; j++) {
      if (dp[i][j]) {
        startAt[i] = max(startAt[i], j - i + 1);
        endAt[j] = max(endAt[j], j - i + 1);
      }
    }
  }

  for (int i = 1; i < n; i++) {
    endAt[i] = max(endAt[i - 1], endAt[i]);
  }

  for (int i = (n - 2); i >= 0; i--) {
    startAt[i] = max(startAt[i + 1], startAt[i]);
  }

  int ans = 0;

  for (int i = 0; i < (n - 1); i++) {
    ans = max(ans, endAt[i] * startAt[i + 1]);
  }

  cout << ans << endl;
}

int32_t main() {
  IOS;
  pre();
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}



