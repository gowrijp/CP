/*
https://www.interviewbit.com/problems/max-product-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

*/

int Solution::maxProduct(const vector<int> &A) {
    int n =A.size();
    int dp1[n];// to maintain max product uptil n
    int dp2[n];// to maintain min product uptil n
    dp1[0]=A[0];
    dp2[0]=A[0];
    for(int i =1;i<n;i++){
        dp1[i]= max(A[i],max(A[i]*dp1[i-1],A[i]*dp2[i-1]));
        dp2[i]= min(A[i],min(A[i]*dp1[i-1],A[i]*dp2[i-1]));
    }
    int ans= INT_MIN;
    for(int i =0;i<n;i++){
        ans= max(ans,dp1[i]);
    }
    return ans;
}
