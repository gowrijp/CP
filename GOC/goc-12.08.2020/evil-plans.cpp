/*
https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/evil-plans

*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q,r;
    cin>>n>>m>>q>>r;
    vector<vector<int>> arr(n, vector<int> (m, 0));
    vector<vector<int>> arr1(n, vector<int> (m, 1));
    if(q>=n*m-1 || r>=n+m-2){
        arr=arr1;
    } 
    else if(q+r>=n+m-1 && r>=(n-q/n)){
        arr=arr1;
    }
    else{
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        arr[x][y]=1;
        int topr=max(0,x-r);
        int botr=min(n-1,x+r);
        int leftc=max(0,y-r);
        int rightc=min(m-1,y+r);
        for(int i=topr;i<=botr;i++){
            for(int j=leftc;j<=rightc;j++){
                if(abs(j-y)+abs(i-x)<=r) arr[i][j]=1;
            }
        }
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}
