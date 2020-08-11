/*
https://www.interviewbit.com/problems/rotate-matrix/

First take transpose
then reverse every row

*/

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    for( int i = 0 ; i < n ; i++ ) 
    {
        for( int j = i+1 ; j < n ; j++ ) 
        {
            swap( A[i][j] , A[j][i] );
        }
    }
    int start = 0 , end = n - 1;
    while (start < end )
    {
        for(int i = 0 ; i < n ; i++ )
        {
            swap( A[i][start] , A[i][end] );
        }
        start++;
        end--;
    }
}
