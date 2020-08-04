/*
https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]

SOLUTION STEPS:
1. Create a vector m of value, pair(x,y) of all elements in the given matrix
2. Sort vector m on basis of value descending order (defined in bool)
3. Iterate for every i and j , i.e. for every value in matrix B through vector m to find the max element in the kth-manhattan distance neighbourhood
4. Populate answer matrix in this way

*/

#include<bits/stdc++.h>
typedef pair<int,pair<int,int>> kamesh;
bool fun(kamesh a, kamesh b){
    return a.first>b.first;
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n=B.size();
    int m1=B[0].size();
    vector<kamesh> m(n*m1);
    int k=0;
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B[i].size();j++){
            m[k]=make_pair(B[i][j],make_pair(i,j));
            k++;
        }
    }
    sort(m.begin(),m.end(),fun);
    int x=m.size();
    vector<vector<int>> v(B.size(),vector<int> (B[0].size()));
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B[i].size();j++){
            for(int l=0;l<x;l++){
                if((abs(i-(m[l].second).first)+abs(j-(m[l].second).second))<=A){
                    v[i][j]=m[l].first;
                    break;
                }
            }
        }
    }
    
    return v;
}
