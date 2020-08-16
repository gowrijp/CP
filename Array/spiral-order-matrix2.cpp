/*
https://www.interviewbit.com/problems/spiral-order-matrix-ii/

Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans(A,vector<int>(A));
    int i = 0;
    int t = 0,t1 =0,t2 =0,t3=0;
    while(1){
        for(int x=t; x<A-t; x++){
            i++;
            ans[t][x] = i;
        }
        t++;
        if(i==A*A)
            break;
        for(int x=1+t1; x<A-1-t1; x++){
            i++;
            ans[x][A-1-t1] = i;
        }
        t1++;
        
        if(i==A*A)
            break;
        
        for(int x=A-1-t2; x>=t2; x--){
            i++;
            ans[A-1-t2][x] = i;
        }
        t2++;
        
        if(i==A*A)
            break;
        
        for(int x = A-2-t3; x>t3; x--){
            i++;
            ans[x][t3] = i;
        }
        t3++;
        
        if(i==A*A)
            break;
    }
    
    return ans;
}

