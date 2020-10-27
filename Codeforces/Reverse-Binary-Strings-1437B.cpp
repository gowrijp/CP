// https://codeforces.com/contest/1437/problem/B

#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
int main(){
 SPEED;
 int t,n;
 cin >> t;
 
 while (t--) {
  cin>>n;
  int a = 0,b = 0;
  string s; cin>>s;
  for(int i=1;i<n;i++){
     if(s[i] == '0' && s[i-1] == '0') a++;
     if(s[i] == '1' && s[i-1] == '1') b++;
  }
 cout<<max(a,b)<<"\n";
 }
 
 return 0;
 
}
