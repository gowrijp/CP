/*
https://www.interviewbit.com/problems/palindrome-partitioning-ii/

Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.
*/

#include<bits/stdc++.h>
using namespace std;

int minCut(string A) {
        int n = A.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;   //cut=[-1,0,1,2,3,4,5,6,7,8]
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && A[i-j]==A[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && A[i-j+1] == A[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
}

int main(){
    string A = "fanbnakgk";         //ans = 2
    minCut(A);
}
