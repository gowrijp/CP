/*You are given two array A[] and B[]. Your task is to arrange elements of first array according to the order defined by second array. The first array contains integers which represent heights of persons and second array defines how many persons in front of him should stand with height greater than or equal to that person.

Input:
First line of input contains number of testcases T. For each testcase, there will be three lines, first of which will contain an integer N denoting the size of the array. Second line contains N space separated integers for array A[] denoting the height of the persons and last line of the test case contains the arrangement array B[].

Output:
Print the result array showing the new height arrangement.

Your Task:
You don't need to read input or print output. Your task is to complete the function arrange() that takes array A, array B, integer N as input parameters and returns a list of integers denoting the new arrangement of people according to their heights. 

Constraints:
1 <= T <= 50
1 <= N <= 103
1 <= A[i] <= 104
1 <= B[i] <= N

Example:
Sample Input:
2
3 
3 2 1
0 1 1
6
5 3 2 6 1 4
0 1 2 0 3 2

Sample Output:
3 1 2
5 3 2 1 6 4 

Explanation:
Testcase 1: 
The output is :                 3 1 2
Corresponding B value:  0 1 1
0 people of greater or equal height in front of person of height 3. 
1 person of greater or equal height in front of person of height 1. 
1 person of greater or equal height in front of person of height 2.

Testcase 2: 
The output is :                 5 3 2 1 6 4 
Corresponding B value:  0 1 2 3 0 2*/

#include <bits/stdc++.h>
using namespace std;

vector<int> arrange(vector<int> &A, vector<int> &B, int n) 
{
    vector<pair<int, int> > arr;
    for(int i = 0; i < A.size(); i++){
        pair<int, int> temp = {A[i], B[i]};
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    cout<<"the sorted arr-----"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
    A.clear();
    for(int i = arr.size()-1; i >=0; i--){
        A.insert(A.begin()+ arr[i].second, arr[i].first);
    }
    return A;
}
int main(){
    //int t;cin>>t;
    int t=1;
    while(t--){
        int n=6; 
        //cin>>n;
        //vector<int> a(n,0);
        vector<int> a={5,3,2,6,1,4};
        //vector<int> b(n,0);
        vector<int> b = {0,1,2,0,3,2};
        /*for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }*/
        vector<int> result = arrange(a,b,n);
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}