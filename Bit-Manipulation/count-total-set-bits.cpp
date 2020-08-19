/*
https://www.interviewbit.com/problems/count-total-set-bits/

Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.
Return the count modulo 109 + 7.
Problem Constraints : 1 <= A <= 109
Input Format : First and only argument is an integer A.
Output Format: Return an integer denoting the ( Total number of set bits in the binary representation of all the numbers from 1 to A )modulo 109 + 7.
Input 1: A = 3
Output 1: 4
Explanation 1:

 DECIMAL    BINARY  SET BIT COUNT
    1          01        1
    2          10        1
    3          11        2
 1 + 1 + 2 = 4 
 Answer = 4 % 1000000007 = 4
 
Input 2: A = 1
Output 2: 1

Explanation 2:

 A = 1
  DECIMAL    BINARY  SET BIT COUNT
    1          01        1
 Answer = 1 % 1000000007 = 1

*/

#define mod 1000000007
#define ll long long int
int Solution::solve(int A) {
    ll a = (ll)A;
    ll cnt = 2;
    ll ans = 0;
    ll temp = 0;
    for(int i=0;i<31;i++)
    {
        temp = (a+1)/cnt;
        ans += (cnt/2)*temp;
        ans %= mod;
        temp = (a+1)%cnt;
        if(temp-cnt/2>0)
        {
            ans+=(temp-cnt/2);
            ans%=mod;
        }
        cnt = cnt<<1;
        // cout<<cnt<<endl;
    }
    return ans;
}
