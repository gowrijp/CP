/*Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
Input : A : [1 5 3]  k : 2
Output : 1
as 3 - 1 = 2
Return 0 / 1 for this problem.
*/
#include<bits/stdc++.h>
using namespace std;

int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int, int> mp;
    for(int i=0; i<A.size(); i++)
    {
        if(mp.find(A[i]+B)!=mp.end()) return 1;
        if(mp.find(A[i]-B)!=mp.end()) return 1;
        mp[A[i]]++;
    }
    return 0;
}