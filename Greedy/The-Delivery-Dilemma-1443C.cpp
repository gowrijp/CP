// https://codeforces.com/contest/1443/problem/C

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        pair<ll,ll> a[n+1];
        ll b[n+2];
        for(int i=1;i<=n;i++) cin>>a[i].first;
        for(int i=1;i<=n;i++) cin>>a[i].second;
        sort(a+1,a+n+1);
        b[n+1]=0;
        for(int i=n;i>=1;i--){
            b[i]=b[i+1]+a[i].second;
        }
        ll ans = b[1];
        for(int i=1;i<=n;i++){
            ans=min(ans,max(a[i].first, b[i+1]));
        }
        cout<<ans<<"\n";
    }
}
