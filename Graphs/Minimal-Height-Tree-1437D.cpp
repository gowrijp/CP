// https://codeforces.com/contest/1437/problem/D

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>h(n,int(1e9));
        h[0]=0;
 
        int cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                cnt++;
            }
            h[i]=h[cnt]+1;
        }
        cout<<h[n-1]<<endl;
    }
    return 0;
}
