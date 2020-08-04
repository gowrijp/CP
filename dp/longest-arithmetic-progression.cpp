/*Find longest Arithmetic Progression in an integer array A of size N, and return its length.
More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.
Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an 
Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]
Note: The common difference can be positive, negative or 0.

Input 1:
    A = [3, 6, 9, 12]
Output 1:
    4
Explanation 1:
    [3, 6, 9, 12] form an arithmetic progression.

Input 2:
    A = [9, 4, 7, 2, 10]
Output 2:
    3
Explanation 2:
    [4, 7, 10] form an arithmetic progression.*/


// eg consider eg 2 above : if i=1 i.e. A[1]=4 j=2,3,4 
// for j=2 diff=7-4=3 dp[2][3]=2
// now again when i=2 i.e. A[2]=7 j=3,4
// for j=4 diff=10-7=3 but now dp[2][3] exists and is equal to 2 
// so dp[4][3] = dp[2][3]+1=3 Hence output = 3 

int Solution::solve(const vector<int> &A) {
    int n=A.size();
    if(n<=2) return n;
    vector<unordered_map<int,int>> dp(n);
    int max_len =2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){                 
            int diff=A[j]-A[i];
            if(dp[i].find(diff)!=dp[i].end()){
                dp[j][diff]=dp[i][diff]+1;
            }
            else{
                dp[j][diff]=2;
            }
            max_len=max(max_len,dp[j][diff]);
        }
    }
    return max_len;
}
