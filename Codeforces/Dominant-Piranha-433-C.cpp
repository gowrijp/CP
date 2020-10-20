// https://codeforces.com/contest/1433/problem/C

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int mx = 0;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            mx = max(mx, v[i]);
        }
        int res = -1;
        for (int i = 0; i < n; i++){
            if (v[i] == mx){
                if (i > 0 && v[i - 1] < mx){
                    res = i + 1;
                    break;
                }
                if (i < n - 1 && v[i + 1] < mx){
                    res = i + 1;
                    break;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
