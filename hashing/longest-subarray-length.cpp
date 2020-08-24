/*
https://www.interviewbit.com/problems/longest-subarray-length/

Given an integer array A of size N containing 0's and 1's only.
You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.
Problem Constraints
1 <= N <= 105
Input Format
First and only argument is an integer array A of size N.
Output Format
Return an integer denoting the longest length of the subarray.

Input 1: A = [0, 1, 1, 0, 0, 1]
Input 2: A = [1, 0, 0, 1, 0]

Output 1: 5
Output 2: 1

Explanation 1: Subarray of length 5, index 1 to 5 i.e 1, 1, 0, 0, 1. Count of 1 = 3, Count of 0 = 2.
Explanation 2: Subarray of length 1 will be only subarray that follow the above condition.
*/

int Solution::solve(vector<int> &a) {

    int n=a.size();
    int s=0,mx=0;
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++){
        if(a[i]==0){
            s--;
        }   
        else{
            s++;
        }
        if(s==1){
            mx=i+1;
        }
        else if(m.find(s)==m.end()){
            m[s]=i;
        }
        if(m.find(s-1)!=m.end()){
            mx=max(mx,i-m[s-1]);
        }
    }
    
    return mx;
}
