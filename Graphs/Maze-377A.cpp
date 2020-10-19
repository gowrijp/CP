// https://codeforces.com/problemset/problem/377/A

// Start BFS or DFS from any free cell. As the maze is connected, this search will visit all s free cells. But we can stop the search when it visits s - k free cells.
// It's obvious that these s - k cells are connected to each other. Remaining k cells can be transformed into the walls.

#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[600][600]={};
int visited[600][600]={};
 
void dfs(int i, int j){
  visited[i][j]=1;
  if(arr[i][j+1]==1&&!visited[i][j+1]){
    dfs(i,j+1);
  }
  if(arr[i+1][j]==1&&!visited[i+1][j]){
    dfs(i+1,j);
  }
  if(arr[i][j-1]==1&&!visited[i][j-1]){
    dfs(i,j-1);
  }
  if(arr[i-1][j]==1&&!visited[i-1][j]){
    dfs(i-1,j);
  }
  if(k){
    arr[i][j]=3;
    k--;
  }
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  int first[2]={-1,-1};
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char t;
      cin >> t;
      if(t=='.'){
        if(first[0]==-1){
          first[0]=i;
          first[1]=j;
        }
        arr[i][j]=1;
      }
      if(t=='#') arr[i][j]=2;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==1){
        dfs(i,j); break;
      }
    }
  }
 
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==1) cout << '.';
      if(arr[i][j]==2) cout << '#';
      if(arr[i][j]==3) cout << 'X';
    }
    cout << endl;
  }
}
