//https://codeforces.com/contest/1421/problem/B

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    queue<pair<int,int> >ans;
    if(s[1][0]==s[0][1]){
        if(s[n-1][n-2]==s[1][0]){
            ans.push({n,n-1});
        }
        if(s[n-2][n-1]==s[1][0]){
            ans.push({n-1,n});
        }
    }
    else if(s[n-1][n-2]==s[n-2][n-1]){
        if(s[1][0]==s[n-1][n-2]){
            ans.push({2,1});
        }
        if(s[0][1]==s[n-1][n-2]){
            ans.push({1,2});
        }
    }
    else{
        if(s[0][1]=='1') ans.push({1,2});
        else ans.push({2,1});
        if(s[n-1][n-2]=='0') ans.push({n,n-1});
        else ans.push({n-1,n});
    }
    cout<<ans.size()<<"\n";
    while(ans.size()){
        cout<<ans.front().first<<" "<<ans.front().second<<"\n";
        ans.pop();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}
