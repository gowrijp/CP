/*
https://codeforces.com/problemset/problem/1398/C

SOLUTION : https://codeforces.com/blog/entry/81506
*/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string a;cin>>a;
        int sum=0;
        long long int good=0;
        unordered_map<int,int> freq;
        freq[0]=1;
        for(int i=0;i<n;i++){
            sum+=a[i]-'0';
            int x=sum-i-1;
            freq[x]++;
            good+=freq[x]-1;
        }
        cout<<good<<endl;
    }
}
