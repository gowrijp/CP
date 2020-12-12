// https://codeforces.com/contest/1461/problem/B

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int mat[n][m];
        for(int i=0;i<n;i++){
            string s; cin>>s;
            for(int j=0;j<m;j++){
                mat[i][j]=(s[j]=='*');
            }
            
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<m-1;j++){
                if(mat[i][j] and mat[i+1][j]){
                    mat[i][j]+=min(mat[i+1][j-1],mat[i+1][j+1]);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=mat[i][j];
            }
        }
        
        cout<<ans<<"\n";
            
    }
    return 0;
}
