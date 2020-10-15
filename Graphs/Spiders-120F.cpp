// https://codeforces.com/problemset/problem/120/F
// DFS on each spider to get maximum depth and sum over each spider

#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> poi(105);
int depth[105];
 
void dfs1(int now,int fa,int dep){
    depth[now] = dep;
    int si = poi[now].size();
    if(si==0) return ;
    for(int i = 0;i<si;i++){
        int son = poi[now][i];
        if(son==fa) continue;
        dfs1(son,now,dep+1);
    }
}
 
int cal(void){
    int p,a,b;
    cin>>p;
    for(int i = 0;i<=p;i++) {
        poi[i].clear();
    }
    for(int i = 1;i<p;i++){
        cin>>a>>b;
        poi[a].push_back(b);
        poi[b].push_back(a);
    }
    dfs1(1,0,0);
    int ind = -1;
    int maxm = 0;
    for(int i = 1;i<=p;i++){
        if(depth[i]>maxm){
            maxm = depth[i];
            ind = i;
        }
    }
    dfs1(ind,0,0);
    maxm = 0;
    for(int i = 1;i<=p;i++)
        maxm = max(maxm,depth[i]);
    return maxm;
}
 
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ans = 0;
    int len;
    cin>>len;
    while(len--){
        ans+=cal();
    }
    cout<<ans<<"\n";
    return 0;
}
