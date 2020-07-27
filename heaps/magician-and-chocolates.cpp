/*Given N bags, each bag contains Bi chocolates. There is a kid and a magician. 
In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician 
fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

NOTE:
floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7

Input Format
First argument is an integer A.
Second argument is an integer array B of size N.
Output Format
Return an integer denoting the maximum number of chocolates that kid can eat in A units of time.

Input 1:
 A = 3
 B = [6, 5]             Output : 14
Input 2:
 A = 5
 b = [2, 4, 6, 8, 10]   Outout : 33

Example Explanation
Explanation 1:

 At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates. 
 At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates. 
 At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate. 
 so, total number of chocolates eaten are 6 + 5 + 3 = 14*/

#include<bits/stdc++.h>
using namespace std;

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> hp;
    int n=B.size();
    int cost=0;
    for(int i=0;i<n;i++){
        hp.push(B[i]);
    }
    while(A--){
        int top=hp.top();
        hp.pop();
        cost+=top%1000000007;
        hp.push(top/2);
        cost=cost%1000000007;
    }
    return cost%1000000007;
}


int main(){
    vector<int> inp={2147483647, 2000000014, 2147483647};
    int A=10;
    cout<<nchoc(A,inp)<<endl;
}