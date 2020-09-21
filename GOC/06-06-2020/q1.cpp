/*Q1:Assembly Line
There are n students standing in an Assembly line.
The height of i-th student from front is Hi meters.
 A student can only see a student in front of him/her
 Also a student y is visible to a Student x if and only if all the heights of students between x and y is strictly less than Hx and y is standing ahead of x.
 You need to find number of ordered pairs (x,y) such that student at position x can see student at position y.

 eg:
4
3 2 3 5

Ans: 4
The possible pairs are (X, Y) = (3,2) , (4,1) , (4,2) , (4, 3)

This is a standard problem which is done using stacks.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i = 1;i<=n;i++) cin>>a[i];
    stack<int> st;
    vector<int> pge(n+1,0);
    for(int i = n; i >= 1;i--){
        while(!st.empty() and a[st.top()]<=a[i]){
            pge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        pge[st.top()] = 0;
        st.pop();
    }
    long long ans  = 0;
    for(int i = 1;i<=n;i++){
        int j = pge[i];
        ans += i - j  - 1;
    }
    cout<<ans<<endl;

}
