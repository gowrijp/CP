/* https://www.interviewbit.com/problems/rain-water-trapped/

Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Problem Constraints
1 <= |A| <= 100000
Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining.
Example Input
Input 1:
A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]  - Output 6
Input 2:
A = [1, 2]   - Output =0
*/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &A){
    int total =0;
    int n=A.size();
    int left[n],right[n];
    left[0]=A[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],A[i]);
    }
    right[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],A[i]);
    }
    for(int i=1;i<n-1;i++){
        total+=min(left[i],right[i])-A[i];
    }
    return total;
}

int main(){
    vector<int> inp={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trap(inp)<<endl;
}