/*
https://www.interviewbit.com/problems/merge-intervals/

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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ans;
    int i;
    //Inserted the newInterval into intervals - Time - O(N). Here sorting can be avoided to save time.
    for(i=0;i<intervals.size();i++){
        if(newInterval.start<=intervals[i].start){
            intervals.insert(intervals.begin()+i,newInterval);
            break;
        }
    }
    //main code - O(N)
    if(i==intervals.size())intervals.push_back(newInterval);
    for(i=0;i<intervals.size();i++){
        if(i==intervals.size()-1)ans.push_back(intervals[i]);
        else if(intervals[i+1].start>intervals[i].end)ans.push_back(intervals[i]);
        else {
            intervals[i+1].start=intervals[i].start;
            intervals[i+1].end=max(intervals[i].end,intervals[i+1].end);
        }
    }
    return ans;
}
