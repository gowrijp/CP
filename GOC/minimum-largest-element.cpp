/*
https://www.hackerrank.com/contests/goc-cdc-series-5/challenges/minimum-largest-element/problem

Binary Search approach
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ff first
#define ss second
typedef long long ll;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        ll l=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            l=max(l,a[i]);
        }
        ll r=1e18;
        ll ans;
        while(l<=r){
            ll mid=(l+r)/2;
            ll ctr=0;
            for(int i=0;i<n&&ctr<k;i++)
                ctr+=(mid-a[i])/(i+1);
            if(ctr>=k){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
