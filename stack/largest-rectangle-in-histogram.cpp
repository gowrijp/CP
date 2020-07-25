/*Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.
eg: [2,1,5,6,2,3]
largest rectangle area = 10
i.e. 5*2
*/
#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &a) {      //a=[2,1,5,6,2,3]
        int m= a.size(), ans=0;                 //m=6, ans=0
        stack<int> s;
        for(int j=0; j<m; j++) {
            if(s.empty() || a[s.top()]<a[j]){
                s.push(j);
                cout<<"pushing "<<j<<" into the stack"<<endl;
            }  
            else {
                while(!s.empty() && a[s.top()]>=a[j]) {
                    int ht= a[s.top()]; s.pop();
                    cout<<"value of ht is ->"<<ht<<endl;
                    if(!s.empty()){
                        ans= max(ans, (j-s.top()-1)*ht);
                    } 
                    else ans= max(ans, j*ht);
                    cout<<"ans value "<<ans<<endl;
                }
                s.push(j);
            }
        }
        while(!s.empty()) {
            int ht= a[s.top()]; s.pop();
            if(!s.empty()) ans= max(ans, (m-s.top()-1)*ht);
            else ans= max(ans, m*ht);
        }
    return ans;
}

int main(){
    vector<int> A={2,1,5,6,2,3};
    cout<<largestRectangleArea(A)<<endl;
}
