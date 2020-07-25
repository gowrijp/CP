/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.



Input Format

The only argument given is character array A.
Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.
For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6
*/
#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    return (s == "+" or s=="-" or s=="*" or s=="/");
}
int Solution::evalRPN(vector<string> &arr) {    //4,13,5,/,+  -> 4 + 13/5 = 6
    int n = arr.size(), val1, val2, res = 0;
    if(n == 0)
        return 0;
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!check(arr[i]))
            st.push(stoi(arr[i]));       //st = 5,13,4
        else {
            val1 = st.top();            //val1=5
            st.pop();
            val2 = st.top();            //val2=13
            st.pop();
            if(arr[i] == "+")
                res = val1+val2;
            else if(arr[i] == "-")
                res = val2-val1; 
            else if(arr[i] == "*")
                res = val1*val2;
            else if(arr[i] == "/")
                res = val2/val1;
            st.push(res);               //st= 2,4  // st=6
        }
    }
    return st.top();                   // ans=6
}
