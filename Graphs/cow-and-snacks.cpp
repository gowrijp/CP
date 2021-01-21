// https://codeforces.com/contest/1209/problem/D

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
