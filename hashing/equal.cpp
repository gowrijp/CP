/*Given an array A of integers, find the index of values that satisfy A + B = C + D, where 
A,B,C & D are integers values in the array

Note:
1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 
2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 
Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2
S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> equal(vector<int> &A) {
    int n=A.size();
    map<int,vector<int>> hash;
    vector<vector<int>> res;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(hash.find(A[i]+A[j])==hash.end()){
                hash[A[i]+A[j]].push_back(i);
                hash[A[i]+A[j]].push_back(j);
            }
            else{
                int x=hash[A[i]+A[j]][0];
                int y=hash[A[i]+A[j]][1];
                if(x<i && y!=i && y!=j)
                    res.push_back({x,y,i,j});
            }
        }
    }
    sort(res.begin(),res.end());
    return res[0];
}

int main(){
    vector<int> A={3, 4, 7, 1, 2, 9, 8};    //test input
    vector<int> out = equal(A);
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<" ";
    }
}