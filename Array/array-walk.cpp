/*
https://codeforces.com/problemset/problem/1389/B

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

int a[MAXN];

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    for (int i = 0; i < n; ++i)  cin >> a[i]; 
    int ans = 0;
    for (int i = 0; i <= k; ++i)  ans += a[i]; 
    for (int p = 1; p <= z; ++p) {
        int q = k - 2 * p;
        if (q < 0)  break; 
        int sum = 0, mmax = 0;
        for (int i = 0; i <= q; ++i) {
            sum += a[i];
            if (a[i] + a[i + 1] > mmax)  
                mmax = a[i] + a[i + 1]; 
        }
        sum += mmax * p;
        if (sum > ans)  
            ans = sum; 
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
