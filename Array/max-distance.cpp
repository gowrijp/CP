/*
https://www.interviewbit.com/problems/max-distance/

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
Input Format
First and only argument is an integer array A.
Output Format
Return an integer denoting the maximum value of j - i;
Example Input
Input 1:  A = [3, 5, 4, 2]
Example Output
Output 1: 2

*/

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> v;
    int i,n=A.size(),mini=INT_MAX,p=0;
    for(i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++){
        if(v[i].second<mini)
            mini=v[i].second;
        else if(v[i].second-mini>p)
            p=v[i].second-mini;
    }
    return p;
}
