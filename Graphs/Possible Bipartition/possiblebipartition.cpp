/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

VIDEO SOLUTION : https://www.youtube.com/watch?v=0ACfAqs8mm0

NOTES OF SOLUTION : BLACK DIARY (page : oct 3 2015)
*/
class Solution {
    bool isBipartite(vector<vector<int>> &adj,int N,int node,vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int ele: adj[curr]){
                if(color[ele]==color[curr]){
                    return false;
                }
                if(color[ele]==-1){
                    color[ele]=1-color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> adj(N+1);
        for(int i=0;i<dislikes.size();++i){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(N+1,-1);
        for(int i=1;i<=N;++i){
            if(color[i]==-1){
                if(!isBipartite(adj,N,i,color)){
                    return false;
                }
            }
        }
        return true;
    }
};
