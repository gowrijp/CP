// https://codeforces.com/contest/1437/problem/C

#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int main(){
    fast_io;
 
    int t;cin >> t;
 
    while (t--){
        int n; cin >> n;
 
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
 
        vector<int> dp(n + 1, 1e5);
        dp[0] = 0;
        for (int i = 1; i <= 2 * n; i++){
            for (int j = n; j > 0; j--){
                dp[j] = min(dp[j], dp[j - 1] + abs(a[j - 1] - i));
            }
        }
 
        cout << dp[n] << endl;
    }
 
    return 0;
}
