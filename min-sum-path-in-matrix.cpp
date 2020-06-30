/*Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.
NOTE: You can only move either down or right at any point in time.
Input Format
First and only argument is an 2D integer array A of size M x N.

Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).
Input 1:

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]

Output 1:9
 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8
*/
int Solution::minPathSum(vector<vector<int> > &A) {
    int r=A.size(),c=A[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(j>=1&&i>=1)A[i][j]=A[i][j]+min(A[i-1][j],A[i][j-1]);
            if(j>=1&&i<1) A[i][j]=A[i][j]+A[i][j-1];
            if(j<1&&i>=1) A[i][j]=A[i][j]+A[i-1][j];
        }
    }
    return A[r-1][c-1];
}
