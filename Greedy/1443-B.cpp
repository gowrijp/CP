// https://codeforces.com/contest/1443/problem/B

/*
SOLUTION:-
Since the activation of any mine explodes the entire segment of mines, which it is, you can immediately replace the input string with an array of mine segments. 
We now have two operations. We can delete any segment by a coins, or turn two adjacent segments [l1,r1], [l2,r2] (r1<l2) into one segment for b⋅(l2−r1). 
That is, two segments can be deleted for a cost of 2⋅a or a+b⋅(l2−r1). This means that you need to merge two segments while b⋅(l2−r1)≤a. You need to go through all adjacent 
segments and check this condition.
*/

#include<bits/stdc++.h>
using namespace std;
 
int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t; cin>>t;
   while(t--){
       int i,a,b,cnt=1e5,sum=0;
       cin>>a>>b;
       string s;
       cin>>s;
       for(i=0;i<s.length();i++){
           if(s[i]=='0') cnt++;
           else{
               sum+=min(cnt*b,a);
               cnt=0;
           }
       }
       cout<<sum<<endl;
   }
}
