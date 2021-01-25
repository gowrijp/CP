//https://codeforces.com/problemset/problem/1475/A

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        if (n==0) cout<<"NO"<<endl;
        // checking if the num is a power of 2 using log2
        else if(ceil(log2(n)) == floor(log2(n))) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
