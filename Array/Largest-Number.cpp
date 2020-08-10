/*
https://www.interviewbit.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

STOLL: To convert a string to long long int
*/

#define ll long long int
bool criteria(int x, int y){
    ll xy=stoll(to_string(x)+to_string(y));
    ll yx=stoll(to_string(y)+to_string(x));
    return xy>=yx;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> B(A);
    string ans="";
    sort(B.begin(),B.end(),criteria);
    for(auto val:B){
        ans+=to_string(val);
    }
    return(ans[0]=='0')?"0":ans;
}

