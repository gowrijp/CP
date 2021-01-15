// https://codeforces.com/problemset/problem/1472/C

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        
        for(int &x: a) cin>>x;
        vector<int> dp(n);
        
        for(int i=n-1;i>=0;i--){
            dp[i]=a[i];
            int j = i+a[i];
            if(j<n) dp[i]+=dp[j];
        }
        
        cout<<*max_element(dp.begin(),dp.end())<<endl;
    }
    return 0;
}
