/*
https://www.interviewbit.com/problems/merge-overlapping-intervals/
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compareInterval(Interval a,Interval b){
    return (a.start<b.start);
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> ans;
    int i;
    sort(A.begin(),A.end(),compareInterval);
    for(i=0;i<A.size();i++){
        if(i==A.size()-1) ans.push_back(A[i]);
        else if(A[i+1].start>A[i].end) ans.push_back(A[i]);
        else {
            A[i+1].start=A[i].start;
            A[i+1].end=max(A[i].end,A[i+1].end);
        }
    }
    return ans;
}

