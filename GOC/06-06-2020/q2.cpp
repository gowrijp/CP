/*Q2: K-Odd Array ----------------Hashing
Given an array of N integers find the number of subarrays having exactly K odd integers.
Sample Input:
5 2
2 5 7 8 1
Sample Output:
5
Explanation:
The subarrays(1-based indexing) having exactly 2 odd integers are [1,3],[1,4],[2,3],[2,4],[3,5]

*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

int main()
{
    IOS
    ll n,k;
    cin>>n>>k;
    ll pre[n+1];
    pre[0]=0;
    map<ll,ll> m;
    for(ll i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        ll x;
        cin>>x;
        if(x%2)
            pre[i]++;
        m[pre[i]]++;
    }
    m[pre[0]]++;
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        m[pre[i-1]]--;
        ans+=m[k+pre[i-1]];
    }
    cout<<ans<<endl;
}
