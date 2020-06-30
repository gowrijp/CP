/*Given a number A, return number of ways you can draw A chords in a circle with
2 x A points such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way
and not in other.
Return the answer modulo 109 + 7.
Input 2:
    A = 2

Output 2:
    2

Explanation 2:
    If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
    {(1-2), (3-4)} and {(1-4), (2-3)}.
    So, we return 2.*/
    
int Solution::chordCnt(int n) {
    int i,j;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<=n;i++) {
        long long int tmp = 0;
        for(j=0;j<=n-1;j++) {
            tmp+=((1LL*dp[j])*(1LL*dp[i-1-j]))%1000000007;
            tmp=tmp%1000000007;
        }
        dp[i]=tmp;
    }
    return dp[n];
}
