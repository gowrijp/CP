/*Q7: Another Number Problem ------------Dynamic Programming (number of ways of climbing n stairs problem)

Starting from 0, in one operation you can add either 3, 5 or 10. By repeating this operation you get a sequence of numbers.
 For example 0, 3, 8, 11, 14 is one possible sequence formed by +3,+5,+3,+3.
Two elements at same position in 2 sequences must NOT be same for them to be distinct
Given N, find the number of distinct sequences that have the final number in sequence as N. The answer may be extremely large so output it modulo 1000000007
eg: 10 ----
ans: 2
0,5,10 and 0,10 two ways of reaching 10

eg:15------
ans:4
0,5,10,15
0,3,6,9,12,15
0,5,15
0,10,15  */

#include <bits/stdc++.h>
#define MOD 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
using namespace std;
inline int add(int a, int b){a += b; if(a >= MOD)a -= MOD; return a;}

signed main() {
    IOS
    int n;
    cin >> n;
    vector<int> ans(n+20, 0);
    ans[0] =1;
    for(int x=0;x<n+1;x++)
    {
        ans[x+3]=add(ans[x+3], ans[x]);
        ans[x+5]=add(ans[x], ans[x+5]);
        ans[x+10]=add(ans[x+10], ans[x]);
    }

    cout << ans[n] <<endl;

}
