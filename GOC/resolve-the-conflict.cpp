/*
https://www.hackerrank.com/contests/goc-cdc-series-8/challenges/another-combinatorics-problem

There are n + 1 students in a Computer Science batch at IIT, in which sadly only a single girl is there and the rest are boys. All the boys have distinct roll numbers from 1 to n. As expected all boys want to be friends with the girl and as a result of the competition many boys have started to hate each other.
There are m pairs of boys in the class which dont get along.You are given two arrays a and b of length m where in the boys with roll numbers ai and bi hate each other.Seeing this alarming situation the girl in the batch decides to jump in and announces that she will befriend the guy who computes the number of possible groups in the batch as quickly as possible. Your bestfriend is interested in that girl and comes to you to help him solve this problem.
A group is a continuous interval [L...R] (1<=L<=R<=n) of roll numbers of boys which dont contain any enemy pair.
For instance lets say there are n = 4 boys in the batch and the boys with roll numbers 1 and 3 dont get along and boys with roll numbers 2 and 4 dont get along.
Then the possible groups in the class will be (1), (1, 2), (2), (2, 3), (3), (3, 4), (4) .
Note that (1, 2, 3) isnt a possible group because boys with roll numbers 1 and 3 dont get along.
Similarly the continuous interval (2, 3, 4) is also not a group because boys with roll numbers 2 and 4 dont get along.

NOTE- Large Input Files! Please use fast input output

Input Format

Integer n (Number of boys in the class)
Integer m (Number of hate pairs in the class)
Array a containing m integers
Array b containing m integers

Output Format

Print a single integer containing the number of groups

Sample Input 0

4 
2
1 2 
3 4 
Sample Output 0

7
Explanation 0

This example is already explained in the problem statement itself

Sample Input 1

5
2
1 2 
3 5 
Sample Output 1

11
Explanation 1

The Possible groups are (1),(1,2),(2),(2,3),(2,3,4),(3),(3,4),(3,4,5),(4),(4,5),(5)
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, m; cin>>n>>m;
    vector<int> a(m), b(m); 
    for(int &x: a)cin>>x; 
    for(int &x: b)cin>>x; 
    
    vector<int> prv(n, -1), g[n]; 
    for(int i = 0;i < m; ++i){
        a[i]--; b[i]--; 
        if(a[i] < b[i])prv[b[i]] = max(prv[b[i]], a[i]); 
        if(b[i] < a[i])prv[a[i]] = max(prv[a[i]], b[i]); 
    }
    
    long long ans = 0; 
    for(int l = 0, r = 0; l < n; ++l){
        while(r < n && prv[r] < l)r++; 
        ans += (r - l); 
    }
    cout<<ans<<"\n"; 
    return 0;
}
