/*Q3:Cakewalk
Given a number N find number of ways to express N as sum of two or more consecutive natural numbers.
1<=N<=10^16
eg: 3 -> ans:1 ( 1+2 )

Soln approach:
Let the first term of the sequence be a and number of terms be n.
So the sum of the sequence will be n*(2*a+n-1)/2
So we can simply iterate over all divisors of N and check whether we can get any suitable n and a for it.

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
int32_t main()
{

    int ans=0;
    int n;
    cin>>n;
    n*=2;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            int p=i;
            int te=n/i;
            te-=(i-1);
            if(te>0 and te%2==0)
                ans++;

        }
    }
    cout<<ans<<endl;
}
