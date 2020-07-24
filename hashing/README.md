## Using maps
- unordered_map<int, int> mp;   // key value pairs
- if(mp.find(A[i]+B)!=mp.end()) return 1;  (checking if a key exists or not in the map)
- if(mp.find(A[i])==mp.end()) return 0; (the key does not exist)
- A map can have vector as a key or value in it - ```map<string,vector<int>> mp;``` and then do this to add values to the vector of the map ```mp[str].push_back(i+1);```
- sorting a string - ```sort(str.begin(),str.end());```
- Iterating through a map -
```
for(auto it=mp.begin();it!=mp.end();it++){
        vector<int> v = it->second;
```
-
