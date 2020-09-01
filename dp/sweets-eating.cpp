/*
https://codeforces.com/problemset/problem/1253/C

Tsumugi brought n delicious sweets to the Light Music Club. They are numbered from 1 to n, where the i-th sweet has a sugar concentration described by an integer ai.

Yui loves sweets, but she can eat at most m sweets each day for health reasons.

Days are 1-indexed (numbered 1,2,3,…). Eating the sweet i at the d-th day will cause a sugar penalty of (d⋅ai), as sweets become more sugary with time. A sweet can be eaten at most once.

The total sugar penalty will be the sum of the individual penalties of each sweet eaten.

Suppose that Yui chooses exactly k sweets, and eats them in any order she wants. What is the minimum total sugar penalty she can get?

Since Yui is an undecided girl, she wants you to answer this question for every value of k between 1 and n.

Input
The first line contains two integers n and m (1≤m≤n≤200 000).

The second line contains n integers a1,a2,…,an (1≤ai≤200 000).

Output
You have to output n integers x1,x2,…,xn on a single line, separed by spaces, where xk is the minimum total sugar penalty Yui can get if she eats exactly k sweets.

Examples
input
9 2
6 19 3 4 4 2 6 7 8
output
2 5 11 18 30 43 62 83 121
input
1 1
7
output
7
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m; 
    cin>>n>>m;
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    sort(val.begin(),val.end());
    
    long long sum=0;
    vector<long long> ans(n);
    for(int i=0;i<n;i++){
        sum+=val[i];
        ans[i]=sum;
        if(i>=m){
            ans[i]+=ans[i-m];
        }
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
