## Some basic syntax
- Heaps are mainly implemented using priority queues, which stores its values in such a way that the element at the top is always the max element (based on first value in the p.queue).

### Some syntaxes of priority queue/heap (Max Heap)
```
priority_queue<pair<int,pair<int,int>>> hp;   //p.queue of type eg. 1,(2,3) 
hp.push(make_pair(x,make_pair(y,z)));
pair<int,pair<int,int>> new = hp.top();
hp.pop();
int L = new.second.first;
int R = new.second.second;
```

### Some syntaxes of set
```
set<pair<int,int>> s;
s.insert(make_pair(x,y));
s.find(make_pair(x,y)) == s.end()     // checking if the element is not present in the set
```
### Some syntaxes of maps
```
unordered_map<int,int>mp;
Deleting a key value pair from map :  mp.erase(x);  // where x is the key or first value in map pair
```
