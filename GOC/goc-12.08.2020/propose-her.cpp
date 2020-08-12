/*
https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/propose-her

Finding the maximum number of balanced parenthesis combinations possible given n (i.e. 2n brackets total in the string)
for eg: given n=2 we have to find all combinations such that number of bracket pairs is 2
answers : ()(), (()) count = 2

eg 2: when n=3; i.e. 3 pairs are possible 
answers: ()()(), (())(), ()(()), ((())), (()()) count =5;

*/

#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100 

vector<string> ans;
void _printParenthesis(int pos, int n, int open, int close); 
  
// Wrapper over _printParenthesis() 
void printParenthesis(int n) 
{ 
    if(n > 0) 
        _printParenthesis(0, n, 0, 0); 
    return; 
}      
  
void _printParenthesis(int pos, int n, int open, int close) 
{ 
    static char str[MAX_SIZE];      
      
    if(close == n)  
    {  
        ans.push_back(str);
        return; 
    } 
    else
    { 
        if(open > close)  
        { 
            str[pos] = ')'; 
            _printParenthesis(pos+1, n, open, close+1); 
        } 
          
        if(open < n) 
        { 
        str[pos] = '('; 
        _printParenthesis(pos+1, n, open+1, close); 
        } 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    ans.clear();
    int n;cin>>n; 
    printParenthesis(n); 
    cout<<ans.size()<<"\n";
    int siz=ans.size();
    for(int i=0;i<siz;i++){
        cout<<ans[siz-1-i]<<"\n";
    }
} 

