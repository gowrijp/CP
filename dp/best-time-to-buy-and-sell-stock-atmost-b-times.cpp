/*
Given an array of integers A of size N in which ith element is the price of the stock on day i.

You can complete atmost B transactions.

Find the maximum profit you can achieve.

NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Input 1:
 A = [2, 4, 1]
 B = 2
 Output: 2
 
 Input 2:
 A = [3, 2, 6, 5, 0, 3]
 B = 2
 Output : 7
*/

#include<bits/stdc++.h>

using namespace std;
//vector<vector<int>> dp(3,vector<int>(6));

int solve(vector<int> &prices, int K) {
    int n = prices.size();
    if(n == 0) return 0;
    if (K >=  n/2) {
        int maxPro = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i-1])
                maxPro += prices[i] - prices[i-1];
        }
        return maxPro;
    }
    vector<vector<int>> dp(K+1,vector<int>(n));
    for(int i = 0;i < n;i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= K;i++) {
        dp[i][0] = 0;
    }
    
    for(int i = 1;i < K+1;i++) {
        int maxdiff = -prices[0];
        for(int j = 1;j < n;j++) {
            dp[i][j] = max(dp[i][j-1],prices[j] + maxdiff);
            maxdiff = max(maxdiff,dp[i-1][j] - prices[j]);
        }
    }
    return dp[K][n-1];
}

/*int main(){
    vector<int> prices = {3,2,6,5,0,3};
    int k=2;
    solve(prices,k);
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}*/
