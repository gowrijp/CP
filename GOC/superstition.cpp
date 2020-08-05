/*
given a string of length N keeping on removing k consecutive appearances of any character.
Sample Input 0
8 3
abbcccbb
Sample Output 0
ab

SOLUTION : USING STACKS WHERE VALUE IS A PAIR OF CHAR AND ITS COUNT
initially if the top of stack is not equal to the value push the value with count 1 
if its equal the add 1 to the count of stack top element

*/
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    stack<pair<char,int>> st;
    int i=0;
    for(int i=0;i<n;i++){
        char x=str[i];
        if(st.size()>0 && st.top().second==k){
            char curr=st.top().first;
            while(st.size()>0 && st.top().first==curr){
                st.pop();
            }
        }
        if(st.size()>0 && st.top().first==x){
            st.push(make_pair(x,st.top().second+1));
        }
        else{
            st.push(make_pair(x,1));
        }
    }
    if(st.size()>0 && st.top().second==k){
        char curr=st.top().first;
        while(st.size()>0 && st.top().first==curr){
            st.pop();
        }
    }
    string stack_string = ""; 
    while (st.size() > 0) {
        stack_string += st.top().first; 
        st.pop();
    }
        

    string reduced_string = ""; 

    // reverse the stack string 
    for (i = stack_string.length() - 1; i >= 0; i--) 
        reduced_string += stack_string[i]; 

    cout<<reduced_string<<endl;
}
