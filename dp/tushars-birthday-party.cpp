/*
https://www.interviewbit.com/problems/tushars-birthday-party/
*/

int Solution::solve(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    vector<int> dp(1001,INT_MAX);
    dp[0] = 0;
    int mxe = *max_element(a.begin(),a.end());
    for(int i=1; i<=mxe; i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            if(i-b[j] >= 0)
            {
                dp[i] = min(dp[i],dp[i-b[j]] + c[j]);
            }
        }
    }
    int ans=0;
    for(int i : a) ans += dp[i];
    return ans;
}
