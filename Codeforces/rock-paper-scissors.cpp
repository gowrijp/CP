// https://codeforces.com/problemset/problem/1426/E

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin>>n;
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<n-min(a,n-e)-min(b,n-f)-min(c,n-d)<<" "<<min(a,e)+min(b,f)+min(c,d)<<"\n";
    return 0;
}
