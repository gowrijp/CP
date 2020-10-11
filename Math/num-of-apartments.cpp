// https://codeforces.com/contest/1430/problem/A

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int rem = n%7;
        if(n==1 or n==2 or n==4) cout<<-1<<"\n";
        else if(n==18) cout<<6<<" "<<0<<" "<<0<<"\n";
        else if(n==11) cout<<2<<" "<<1<<" "<<0<<"\n";
        else if(rem==0) cout<<0<<" "<<0<<" "<<n/7<<"\n";
        else if(rem==3 or rem==6) cout<<rem/3<<" "<<0<<" "<<n/7<<"\n";
        else if(rem==5) cout<<0<<" "<<1<<" "<<n/7<<"\n";
        else if(rem==1) cout<<1<<" "<<1<<" "<<(n-8)/7<<"\n";
        else if(rem==2) cout<<3<<" "<<0<<" "<<(n-9)/7<<"\n";
        else cout<<0<<" "<<5<<" "<<(n-25)/7<<"\n";
    }
    return 0;
}
