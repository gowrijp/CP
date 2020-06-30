/* Q-1>>> Max Sum Without Adjacent Elements
Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally,
 and return it.
 Note: You can choose more than 2 numbers.
 Input 1:
    A = [   [1]
            [2]    ]

Output 1:
    2

Explanation 1:
    We will choose 2.

Input 2:
    A = [   [1, 2, 3, 4]
            [2, 3, 4, 5]    ]

Output 2:
    We will choose 3 and 5.*/

int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    vector<int> dp(n+1,0);
    if(n==0) return 0;
    if(n==1) return max(A[0][0],A[1][0]);
    dp[1]=max(A[0][0],A[1][0]);
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+max(A[0][i-1],A[1][i-1]));
    }
    return dp[n];
}


/*Q-2>> Edit Distance
Given two strings A and B, find the minimum number of steps required to
convert A to B. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.*/
  // Did not understand this question well --------------------
int Solution::minDistance(string A, string B) {
    int lengthA = A.length();
    int lengthB = B.length();

    if (lengthA == 0 || lengthB == 0)
    {
        return max(lengthA, lengthB);
    }

    vector<int> cache(lengthB + 1);
    for (int i = 0; i <= lengthB; i++)
    {
        cache[i] = i;
    }

    int lastImpNo;
    for (int i = 1; i <= lengthA; i++)
    {
        lastImpNo = cache[0];
        cache[0] = i;
        for (int j = 1; j <= lengthB; j++)
        {
            int oldVal = cache[j];

            if (A[i - 1] == B[j - 1])
            {
                cache[j] = lastImpNo;
            }
            else
            {
                cache[j] = min(min(lastImpNo, cache[j - 1]), cache[j]) + 1;
            }

            lastImpNo = oldVal;
        }
    }

    return cache[lengthB];
}

/*Q3>>Find the longest increasing subsequence of a given array of integers, A.
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.
Input 1:
    A = [1, 2, 1, 5]

Output 1:
    3

Explanation 1:
    The sequence : [1, 2, 5]

Input 2:
    A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]

Output 2:
    6

Explanation 2:
    The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15] */

int Solution::lis(const vector<int> &A) {

    int n = A.size();
    int lis[n];
    for(int i =0;i<n;i++)
     lis[i]=1;
    for(int i =1;i<n;i++)
    {
        for(int j =0;j<i;j++)
        {
            if(A[i]>A[j] && lis[j]+1>lis[i])
              lis[i]=lis[j]+1;
        }
    }
    int max = lis[0];
    for(int i =1;i<n;i++)
    {
        if(lis[i]>max)
          max = lis[i];
    }
    return max;
}
