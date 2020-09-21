/*Q 6: Jumping Fever ------ Dynamic Programming
N cities in a country. Each city has a cost C[i] that you need to pay if you visit it. Each city has a reachability
A[i] i.e from city i you can jump to city i+1,i+2,....min(N,i+A[i])
Tanishq is currently present in city 1. He wants you to find minimum cost to reach Nth city.
The cost of city 1 must be included in the answer.

Sample Input :
7
3 2 4 6 3 2 6
1 2 1 3 1 2 1

Ans: 17
The path with least cost is through cities 1->2->4->7
*/
#include <iostream>
#include <algorithm>

using namespace std;
#define int long long
#define INF 1e18
int dp[200005];

int solve(int n, int c[], int a[])
{
    dp[0] = 0;
    for(int i=1;i<n;i++)
    {
        dp[i] = INF;
    }
    for (int i=0;i<n;i++)
    {
        dp[i]+=c[i];
        for(int j=i+1;j<=min(n-1,i+a[i]);j++)
        {
            dp[j] = min(dp[j],dp[i]);
        }
    }
    return dp[n-1];
}

int n;
int a[200005];
int c[200005];
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<solve(n,c,a)<<endl;
}
