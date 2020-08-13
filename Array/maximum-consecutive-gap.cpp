/*
https://www.interviewbit.com/problems/maximum-consecutive-gap/

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
*/

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2) return 0;
    int mn=*min_element(A.begin(),A.end());
    int mx=*max_element(A.begin(),A.end()),n=A.size();
    double gap=(double)(mx-mn)/(n-1);
    if(gap==0) return 0;
    vector<int> mx_buc(n,INT_MIN);
    vector<int> mn_buc(n,INT_MAX);
    for(int x:A){
        int ind=floor((x-mn)/gap);
        if(mn==x) continue;
        mx_buc[ind]=max(mx_buc[ind],x);
        mn_buc[ind]=min(mn_buc[ind],x);
    }
    int mx_gp=INT_MIN;
    int prev_mx=mn;
    for(int i=0;i<n;i++){
        if(mn_buc[i]==INT_MAX) continue;
        int cur=mn_buc[i]-prev_mx;
        mx_gp=max(mx_gp,cur);
        prev_mx=mx_buc[i];
    }
    return mx_gp;
}
