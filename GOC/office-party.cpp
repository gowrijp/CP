/*

https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/party-5-1/problem

The company that shall not be named, is organising a party for its N  employees. But not everyone wants to spend their spare time in a party when he won't have many friends 
there. Precisely, each employee goes to the party if and only atleast K of of his/her friends are also going to the party. You are given m relationship pairs, the ith being 
xi,yi denoting that xi and yi are friends.
Find the maximum number of friends that can go the party.

Input format
first line T - Number of test cases
First line of each test case contains three space separated integers n,m,k denoting the number of employees and relationship pairs and the least number of friends that should 
go to the party if someone goes to the party.
Each of the next m lines denotes relationship pairs

For each test case output a single integer in a newline - the maximum number of employees who can attend the party.
Sample Input 0

1 
4 4 2
1 2 
2 3 
3 1
1 4
Sample Output 0

3
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        map<int,vector<int>> d;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            d[x].push_back(y);
            d[y].push_back(x);
        }
        while(true){
            int flag =0;
            map<int,vector<int>>d1;
            for(auto i:d){
                if(i.second.size()>=k){
                    d1[i.first]=i.second;
                }
                else{
                    flag=1;
                }
                
            }
            for(auto i:d1){
                vector<int> temp;
                int siz = i.second.size();
                for(int j=0;j<siz;j++){
                    if(d1.find(i.second[j])!=d1.end()){
                        temp.push_back(i.second[j]);
                    }
                    
                }
                d1[i.first]=temp;
                
            }
            d=d1;
            if(flag==0){
                break;
            }
            
        }
        int count =0;
        for(auto i:d){
            if(i.second.size()>=k){
                count++;
            }
        }
        cout<<count<<endl;
        
        
    }
    
}
