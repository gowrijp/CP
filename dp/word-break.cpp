/*
https://www.interviewbit.com/problems/word-break/

*/
int Solution::wordBreak(string A, vector<string> &B) {
    int n=A.size();
    vector<int> dp(n+1);
    
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(auto si:B)
        {
            int lb = i-si.size();
            if(lb<0)continue;
            
            //si.length back from i'th (indx base 1) character 
            if(A.substr(lb,si.size()) == si && dp[lb])
            {
                dp[i]=1;
                break;
            }
        }
    }
    
    return dp[n];
}
