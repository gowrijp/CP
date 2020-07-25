/*Check a vector of strings return which strings are anagrams (return a 2D vector of indices)
eg: {"cat","das", "dog", "god", "tca", "ogd","enemy"}
output:  [[1, 5], [2], [3, 4, 6], [7] ]
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    int n = A.size();
    map<string,vector<int>> mp;
    for(int i=0;i<n;i++){
        string str = A[i];
        sort(str.begin(),str.end());    //sort the string 
        mp[str].push_back(i+1);
    }
    vector<vector<int>> vect;
    int k=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        vector<int> v = it->second;
        vect.push_back(v);
    }
    return vect;
}

int main(){
    vector<string> words={"cat","das", "dog", "god", "tca", "ogd","enemy"};
    vector<vector<int>> ans = anagrams(words);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
