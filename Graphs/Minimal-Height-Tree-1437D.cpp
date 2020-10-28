// https://codeforces.com/contest/1437/problem/D

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> h(n,0);
        h[0]=0;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                cnt++;
            }
            h[i]=h[cnt]+1;
        }
        cout<<h[n-1]<<"\n";
    }
    return 0;
}
