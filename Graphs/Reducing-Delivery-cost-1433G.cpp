// https://codeforces.com/contest/1433/problem/G

#include <bits/stdc++.h>
using namespace std;   
 
long long n, m, k, cost[1001][1001], ans=2e18;
vector<pair<long long, long long> > edge[1001], edges, routes;
 
void DIST(long long a){
        long long dist[n+1]={};
        for(long long i=1;i<=n;++i) dist[i]=2e18;
        set<pair<long long, long long> > s;
        s.insert({0, a});
        dist[a]=0;
        while(!s.empty()){
                long long dis=s.begin()->first;
                long long node=s.begin()->second;
                s.erase(s.begin());
                for(auto &it: edge[node])
                        if(dist[it.first]>dis+it.second){
                                if(dist[it.first]!=2e18) s.erase(s.find({dist[it.first], it.first}));
                                dist[it.first]=dis+it.second;
                                s.insert({dist[it.first], it.first});
                        }
        }
        for(int i=1;i<=n;++i) cost[a][i]=dist[i];
}
 
int main() {
        ios::sync_with_stdio(0);
        cin>>n>>m>>k;
        for(long long i=0,x,y,w;i<m;++i){
                cin>>x>>y>>w;
                edges.push_back({x, y});
                edge[x].push_back({y, w});
                edge[y].push_back({x, w});
        }
        for(int i=1;i<=n;++i) DIST(i);
        for(int i=0,a,b;i<k;++i){
                cin>>a>>b;
                routes.push_back({a, b});
        }
        for(auto &edg: edges){
                long long nw=0;
                for(auto &rou: routes)
                        nw+=min({cost[rou.first][rou.second], cost[rou.first][edg.first]+cost[edg.second][rou.second], cost[rou.second][edg.first]+cost[edg.second][rou.first]});
                ans=min(ans, nw);
        }
        cout<<ans;
        return 0;
}
