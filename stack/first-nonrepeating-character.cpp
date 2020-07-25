/*eg: abadbc - output : 
a - a
ab - aa
aba - aab
abad - aabb
abadb - aabbd
abadbc- aabbdd
so final ans : aabbdd 

one vector(size 26 initialised with 0) and one queue 
if for the char in input value in vector in 0 push into the queue
then increment value for the char in the vector
if queue is not empty and the value from the char at the front of the queue>1 -> then
    pop from the queue as long as u dont get a char whose value is 1 in the vector
if q is empty append #
else append q.front()

*/
#include<bits/stdc++.h>
using namespace std;

string solve(string A){
    int n = A.size();
    vector<int> repeated(26,0);
    string res = "";
    deque <char> q;
    for(int i=0;i<n;i++){
        if(repeated[A[i]-'a']==0){
            q.push_back(A[i]);
        }
        repeated[A[i]-'a']++;
        while(!q.empty() && repeated[q.front()-'a']>1){
            q.pop_front();
        }
        if(q.empty()){
            res+='#';
        }
        else{
            res+=q.front();
        }
    }
    return res;
}

int main(){
    string s="abadbc";
    cout<<solve(s)<<endl;
}