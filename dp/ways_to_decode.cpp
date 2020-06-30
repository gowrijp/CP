/*A message containing letters from A-Z is being encoded to numbers using the following mapping:
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.
Problem Constraints
1 <= |A| <= 105
Input Format:
The first and the only argument is a string A.
Output Format:
Return a single integer denoting the total number of ways to decode it modulo 109 + 7.
Example Input:

Input 1:
A = "8"
Input 2:
A = "12"

Example Output
Output 1: 1
Output 2: 2
*/

int Solution::numDecodings(string A) {
    int N=A.length();
    int dp[N+1];
    for(int i=0; i<=N; i++){
        dp[i]=0;
    }
    dp[0] = 1;
    dp[1] = A[0]=='0' ? 0 : 1;
    for(int i=2; i<=N; i++){
        int oneDigit=stoi(A.substr(i-1,1));
        int twoDigit=stoi(A.substr(i-2,2));
        if(oneDigit>=1){
            dp[i] += dp[i-1];
        }
        if(twoDigit>=10 && twoDigit<=26){
            dp[i] += dp[i-2];
        }
    }
    return dp[N];
}
