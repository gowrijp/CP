/*
https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/pingpong/problem

SOLUTION
editorial soln :

We can divide the problem in 3 cases:-
1. max(X,Y)<N : Not possible as winner must have atleast N points
2. max(X,Y) = N : a.max(X,Y)-min(X,Y)<=1 - It is not possible because difference must be of atleast 2                              
                         points.
                  b.Otherwise - Last point must be scored by winner. Everything else can be arranged 
                         in (X+Y-1)!/((max(X,Y)-1)!*(min(X,Y))!) ways.
3. max(X,Y)>N :
a.max(X,Y)-min(X,Y)!=2 - It is not possible because as soon as differnce becomes 2 
                         the player with more point wins.
b.max(X,Y)-min(X,Y)==2 - Last  two point must be scored by winner. For such a case  
                         to happen a draw must take place i.e (N-1:N-1). This can
                         be arranged in (2*N-2)!/((N-1)!*(N-1)!) ways. Now till both 
                         of them reach min(X,Y) after every two games from now it
                         must be a draw i.e (N:N),(N+1:N+1),...,(min(X,Y):min(X,Y)). 
                         Each of this can occur in two ways  i.e either first team  
                         wins then second or vice-versa.Therefore total number of 
                         ways = ((2*N-2)!/((N-1)!*(N-1)!))*(2^((X+Y-2*N)/2))
                         
                         
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
#define ff first
#define ss second
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
vector <ll> fact(200001,1);
vector <ll> ifact(200001,1);
void calfact(){
    for(ll i=2;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%MOD;
        ifact[i]=fermat_inv(fact[i]);
    }
}
// solver here
int solve(int n, int x, int y)
{
    int v=min(x,y);
    y=max(x,y);
    x=v;
    ll ans=1ll;
    if(y<n||y-x<=1||(y>n&&y-x>2))
        return 0;
    else if(y==n){
        ans=(fact[x+y-1]*ifact[x])%MOD;
        ans=(ans*ifact[y-1])%MOD;
    }
    else{
        ans=(fact[2*n-2]*ifact[n-1])%MOD;
        ans=(ans*ifact[n-1])%MOD;
        ans=(ans*power(2ll,(x+y-2*n)/2))%MOD;
    }
    return ans;
}
int main(){
    calfact();
    ll t=1;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        cout<<solve(n,x,y)<<"\n";
    }
    return 0ll;
}
