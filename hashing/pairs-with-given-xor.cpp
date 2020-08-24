/*
https://www.interviewbit.com/problems/pairs-with-given-xor/

Problem Description
Given an 1D integer array A containing N distinct integers.
Find the number of unique pairs of integers in the array whose XOR is equal to B.

NOTE: Pair (a, b) and (b, a) is considered to be same and should be counted once.
Problem Constraints
1 <= N <= 105
1 <= A[i], B <= 107

Input Format
First argument is an 1D integer array A.
Second argument is an integer B.

Output Format
Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.
Input 1:
 A = [5, 4, 10, 15, 7, 6]
 B = 5
Input 2:
 A = [3, 6, 8, 10, 15, 50]
 B = 5

Output 1: 1
Output 2: 2

Explanation 1: (10 ^ 15) = 5
Explanation 2: (3 ^ 6) = 5 and (10 ^ 15) = 5 

SOLUTION :
An efficient solution of this problem take O(N) time.
The idea is based on the fact that A[i] ^ A[j] is equal to B if and only if A[i] ^ B is equal to A[j].

Initialize result as 0.
Create an empty hash set “s”.
Do following for each element A[i] in A[]
If B ^ A[i] is in “s”, then increment result by 1.
Insert A[i] into the hash set “s”.
Return result.

*/
int Solution::solve(vector<int> &A, int B) {
    int ans=0;
    unordered_map<int,int> u;
    for(int i=0;i<A.size();i++){
        if(u[A[i]^B]){
            ans++;
        }
        u[A[i]]++;
    }
    return ans;
}
