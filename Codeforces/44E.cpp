//https://codeforces.com/problemset/problem/44/E

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int k,a,b;
    string s; 
    cin>>k>>a>>b>>s; 
    int l=s.length(); 
    if(l>k*b || l<k*a){ 
        cout<<"No solution"; 
        return 0; 
        
    } 
    int n=l/k; 
    if(n+(l%n)>b and (n+1)<=b) n=n+1;
    int i=0,x=0; 
    for(;x<k-1;x++){ 
        for(int j=0;j<n;j++) 
            cout<<s[i++]; 
        cout<<endl; 
    } 
    while(i<l){ 
        cout<<s[i]; i++; 
    }
}
