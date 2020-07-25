/*Given an array S of n integers, are there elements a, b, c, and d in S such that 
a + b + c + d = target? Find all unique quadruplets in the array which gives the sum 
of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR 
(Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])
*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> fourSum(vector<int> &A, int B) {
    map<vector<int>,int>mp;             
    sort(A.begin(),A.end());            
    int n = A.size();                   
    for(int i=0;i<n-3;i++){             
        for(int j=i+1;j<n-2;j++){       
            int a = A[i];
            int b =A[j];
            int start = j+1;
            int end = n-1;
            while(start<end){
                int sum = a+b+A[start]+A[end];
                if(sum==B){
                    vector<int>temp;
                    temp.push_back(a);
                    temp.push_back(b);
                    temp.push_back(A[start]);
                    temp.push_back(A[end]);
                    if(mp.find(temp)==mp.end()){
                        mp[temp] =1;
                    }
                    start++;
                    end--;
                }
                else if(sum>B){
                    end--;
                }
                else{
                    start++;
                }
                
            }
        }
        
    }
    vector<vector<int>>result;
    for(auto it:mp){
        result.push_back(it.first);
    }
    return result;
}

int main(){
    vector<int> A={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans = fourSum(A, target);
    int row = ans.size();
    int col = ans[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
