/*Find out the number of N digit numbers, whose digits on being added equals to a given number S.
 Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.
Since the answer can be large, output answer modulo 1000000007
N = 2, S = 4
Valid numbers are {22, 31, 13, 40}
Hence output 4.*/

#define m 1000000007
int Solution::solve(int A, int B)                 // eg: A=2; B=12
{
    vector<vector<int>> v(A+1, vector<int>(B+1)); // v(3,13) size vector
    
    for(int i=0; i<=min(9,B); i++)
        v[1][i]=1;                               // base case when number of digits = 1 and sum ranges from 0-min(B,9) the number of possibilities is 1
        
    for(int n=2; n<=A; n++)                      // iteration for number of digits=2 onwards
    {
        for(int s=0; s<=B; s++)
        {
            for(int d=0; d<=min(s,9); d++)       
            {
                if(n==A && s==B && d==0)
                    continue;
                v[n][s] = (v[n][s] + v[n-1][s-d])%m;        
            }
        }
    }
    /* This is how the final v matrix looks like :
  i/j0 1 2 3 4 5 6 7 8 9 10 11 12
  0  0 0 0 0 0 0 0 0 0 0  0  0  0 
  1  1 1 1 1 1 1 1 1 1 1  0  0  0
  2  1 2 3 4 5 6 7 8 9 10 9  8  7
    */
    return v[A][B];
}


// Alternate Solution (simple and intuitive)

#include <math.h>
#define ll long long int
int Solution::solve(int A, int B) {
    ll num = pow(10,A);
    ll left=pow(10,A-1);
    ll count=0;
    int digit;
    for(ll i=left;i<num;i++){
        int sum=0;
        while(i>0){
            digit=i%10;
            i=i/10;
            sum+=digit;
        }
        if(sum==B) count++;
    }
    return count%1000000007;
}
