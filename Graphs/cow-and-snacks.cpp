// https://codeforces.com/contest/1209/problem/D

// SOLUTION
// Since every animal has exactly two favorite snacks, this hints that we should model the problem as a graph. The nodes are the snacks, and the edges are animals with preferences connecting snack nodes.
// Let's consider a connected component of the graph with size greater than 1. The first animal (edge) in that component to eat must take two snacks (nodes), all other snack nodes will be eaten by exactly one animal edge. It is always possible to find an order so that no other animals takes two snacks (for example, BFS order). Thus, a connected component with c vertices can satisfy at most c−1 animals.
// Let N be the number of snacks, M be the number of animals, and C be the number of connected components (including those of size 1). The number of satisfied animals is N−C, so the number of of unhappy animals is M−(N−C).

// Complexity: O(n+m)

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ft first
#define sc second
vector<pair<int,int>> adj[200001];
int n,k,r,gs[200001],vis[200001];
 
void bfs(int n)
{
	queue<int> q;
	vis[n]=1;
	q.push(n);
	while(!q.empty())
	{
		int n=q.front();
		q.pop();
		for(int i=0;i<adj[n].size();i++)
		{
			if(vis[adj[n][i].sc])continue;
			vis[adj[n][i].sc]=1;
			gs[adj[n][i].ft]=1;
			q.push(adj[n][i].sc);
		}
	}
}
void solve(){
	cin>>n>>k;
	
	for(int i=1;i<=k;i++){
    	int a,b;
    	cin>>a>>b;
    	adj[a].pb({i,b});
    	adj[b].pb({i,a});
	}
	for(int i=1;i<=n;i++)
	if(!vis[i])bfs(i);
	for(int i=1;i<=k;i++)if(!gs[i])r++;
	cout<<r;
}
int main(){ 
	ios::sync_with_stdio(0); cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
	  solve();
	  cout<<endl;
	}
}
