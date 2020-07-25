/*Given an array of integers A. There is a sliding window of size B which
is moving from the very left of the array to the very right.
You can only see the w numbers in the window. Each time the sliding window moves
rightwards by one position. You have to find the maximum for each window.
The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	        Max
———————————-	        ————————-
[1 3 -1] -3 5 3 6 7	        3
1 [3 -1 -3] 5 3 6 7	        3
1 3 [-1 -3 5] 3 6 7	        5
1 3 -1 [-3 5 3] 6 7	        5
1 3 -1 -3 [5 3 6] 7	        6
1 3 -1 -3 5 [3 6 7]	        7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.
Input Format
    The first argument given is the integer array A.
    The second argument given is the integer B.
Output Format
    Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]
For Example
Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]*/

#include<bits/stdc++.h>
using namespace std;

//This one gives TLE although answer is correct
/*
vector<int> slidingMaximum(vector<int> &A, int B) {
    int n=A.size();
    if(B>=n){
        sort(A.begin(),A.end());
        return {A[n-1]};
    }
    int i=0,j=B-1;
    vector<int> ans;
    while(i<=(n-B)){
        int maximum = A[i];
        for(int k=i;k<=j;k++){
            maximum=max(maximum,A[k]);
        }
        ans.push_back(maximum);
        i++;
        j++;
    }
    return ans;
}
*/
vector<int> slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    vector<int> ans;
    if(B >=n && n!=0){
        ans.push_back(*max_element(A.begin(),A.end()));
        return ans;
    }
    else if(B>=n && n == 0)
        return ans;
    
    deque<int> dq(B);
    
    for(int i =0;i<B;i++)
    {
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    
    for(int i=B;i<n;i++)
    {
        ans.push_back(A[dq.front()]);
        
        while(!dq.empty() && dq.front() <= i - B)
            dq.pop_front();
        
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
    }
    ans.push_back(A[dq.front()]);
    return ans;
}


int main(){
    vector<int> A={1, 3, -1, -3, 5, 3, 6, 7};
    int B=3;
    vector<int> solution = slidingMaximum(A,B);
    int n=solution.size();
    for(int i=0;i<n;i++){
        cout<<solution[i]<<" ";
    }
}