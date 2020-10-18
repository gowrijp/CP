## Some syntax 
```
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```
### Vector

- <b>Declaration:</b>
```
vector<int> p({4,8,15,16,23});  // declaring with values
vector<int> a(n)  // n is size

```
- **Lower bound**
```
int x = lower_bound(p.begin(),p.end(),m)-p.begin();  //gives the position of the element smaller than or equal to m from vector p
```
### Queue
```
queue<pair<int,int>> ans;
ans.push({n,n-1});
ans.front().first;
ans.front().second;
ans.pop();
```
