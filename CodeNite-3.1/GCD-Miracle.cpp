/*
Given an array of length N. Find the length of the maximum subsequence of array say a1 ,a2,....,ak such that gcd(a1,a2…,ak)>1. Also print the value of gcd. If there are multiple gcd possible print maximum among them. If there exist no such sequence, print gcd value equal to 0.

Note : A sequence with a single number has gcd value equal to that number in sequence .

Input Format

First line contains N - length of array
Next line contains N elements of array

Constraints:  1<= N <=100000 1<=A[i]<=1000000

Output Format

Two integers ,first integer is length of maximum subsequence and second integer is the value of maximum gcd

Sample Input 0
4
2 4 6 8
Sample Output 0
4 2
Explanation 0
The subsequence will be 2 4 6 8

Sample Input 1
3
2 3 4
Sample Output 1
2 2
Explanation 1
The subsequence will be 2 4
*/

// EDITORIAL
/*We use the idea that n+n/2+n/3+n/4…..=n(log(n)). We can hash the initial array .After that take each value from 2 to max(A[i]) as gcd and check for their multiples,add the hash value stored in the array for every multiple. This will be the length of maximum subsequence with GCD i . If the array contains all 1 then the answer will be 0 for maximum length . That is no such subsequence exists.*/

#include<bits/stdc++.h>
using namespace std;

int h[1000001];
int main() {
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans_len=0,gcd=0;
    for(int i=0;i<n;i++) {
        h[a[i]]++;
    }
    int mx = *max_element(a, a + n); 
    for(int i=2;i<=mx;i++) {
        int len=0;
        for(int j=i;j<=mx;j+=i) {
            len+=h[j];
        }
        if(len>=ans_len) {
            ans_len=len;
            gcd=i;
        }
    }
    if(ans_len==0) gcd=0;
    cout<<ans_len<<" "<<gcd;
    return 0;
}
