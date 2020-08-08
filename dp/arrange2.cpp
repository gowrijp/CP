/*
https://www.interviewbit.com/problems/arrange-ii/

You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

If a solution is not possible, then return -1

*/

int Solution::arrange(string A, int B) {
    int n=A.size();
    if(n==0){return 0;}
    
    vector<int> dp(n,0);
    int countW=0,countB=0;
    if(B>n){return -1;}
    
    for(int j=n-1; j>=0; j--){
        if(A[j]=='W'){countW++;}
        else{countB++;}
        dp[j] = countW*countB;
    }
    
    for(int k=2;k<=B; k++){
        
        for(int i=0; i<n; i++){
            countW=0;
            countB=0;
            
            for(int j=i; j<n-1;j++){
                if(A[j]=='W'){countW++;}
                else{countB++;}
                
                dp[i]=min(dp[i],countW*countB + dp[j+1]);
            }
        }
    }
    
    return dp[0];
}
