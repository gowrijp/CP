// https://codeforces.com/contest/1433/problem/G

#include<bits/stdc++.h>
using namespace std;
 
int n,m,k, cost[1001][1001], ans=1e9;
vector<pair<int,int>> edge[1001], edges, routes;
 
// Creating the adjacency matrix (with cost of traversing between each i and j nodes)
void find_dist(int a){
    int dist[n+1]={};
    for(int i=1;i<=n;i++) dist[i]=1e9;
    set<pair<int,int>> s;
    s.insert({0,a});
    dist[a]=0;
    while(!s.empty()){
        int dis = s.begin()->first;
        int node = s.begin()->second;
        s.erase(s.begin());
        for(auto &it : edge[node]){
            if(dist[it.first]>dis + it.second){
                if(dist[it.first]!=1e9) s.erase(s.find({dist[it.first], it.first}));
                dist[it.first]=dis+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i=1;i<=n;++i) cost[a][i]=dist[i];
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0,x,y,w;i<m;++i){
            cin>>x>>y>>w;
            edges.push_back({x, y});
            edge[x].push_back({y, w});
            edge[y].push_back({x, w});
    }
    for(int i=1;i<=n;++i) find_dist(i);
    for(int i=0,a,b;i<k;++i){
            cin>>a>>b;
            routes.push_back({a, b});
    }
    // we remove each edge one by one and check in which case we get least total cost for all routes
    for(auto &edg: edges){
            int nw=0;
            for(auto &rou: routes)
                    nw+=min({cost[rou.first][rou.second], cost[rou.first][edg.first]+cost[edg.second][rou.second], cost[rou.second][edg.first]+cost[edg.second][rou.first]});
            ans=min(ans, nw);
    }
    cout<<ans;
    return 0;
}
