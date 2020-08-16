/*
https://codeforces.com/problemset/problem/1391/C

AN EXCELLENT VIDEO EXPLANATION: https://www.youtube.com/watch?v=KffnTAQBp2A
if there is a position/index i which can form cycle on both sides, then its a cyclic permutation.
*/

#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long qpow(long long a,long long n)
{
    long long sum=1;
    while(n)
    {
        if(n&1)
            sum = sum * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return sum;
}
long long n, ans1 = 1, ans2 = 1;
int main()
{
    scanf("%lld", &n);
    for (long long i = 2; i <= n;i++)
    {
        ans1 = (ans1 * i) % mod;
    }
    ans2 = qpow(2ll, n - 1);
    ans1 = (ans1 - ans2 + mod) % mod;
    printf("%lld\n", ans1);
    //system("pause");
    return 0;
}
