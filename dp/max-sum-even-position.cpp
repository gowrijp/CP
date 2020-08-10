/*
https://codeforces.com/problemset/problem/1373/D

YOUTUBE SOLN : https://www.youtube.com/watch?v=nWT4ieeQpdY
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200100;
long long a[MAXN], b[MAXN], dp[MAXN];

void solve() {
    int n = 0;
    long long sum = 0, mx = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    for (int i = 0; i < n; i += 2) { sum += a[i]; }
    for (int i = 1; i < n; i += 2) { b[i] = a[i] - a[i - 1]; }
    for (int i = 2; i < n; i += 2) { b[i] = a[i - 1] - a[i]; }
    dp[1] = b[1];
    dp[2] = b[2];
    ans = max(dp[1], dp[2]);
    for (int i = 3; i < n; ++i) {
        dp[i] = max(b[i], dp[i - 2] + b[i]);
        if (dp[i] > ans) { ans = dp[i]; }
    }
    if (ans > 0) { sum += ans; }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
