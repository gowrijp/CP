/*
https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/a-town-without-me/problem
*/

#include <bits/stdc++.h>
using namespace std;

const int S = 2e6 + 5;
bool supermask[S],submask[S];

void insert_sub(int x){
    if(submask[x])return;
    submask[x] = true;

    for(int i = 0;;i++){
        if(x < (1<<i))return;

        if((x&(1<<i)) == 0)continue;
        insert_sub(x - (1<<i));
    }
}

void insert_super(int x){
    if(supermask[x])return;
    supermask[x] = true;

    for(int i = 0;;i++){
        if(x + (1<<i) >= S)return;

        if((x&(1<<i)) != 0)continue;
        insert_super(x+(1<<i));
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,q,x;
    cin>>n>>q;

    memset(supermask,0,sizeof supermask);
    memset(submask,0,sizeof submask);

    while(n--){
        cin>>x;
        insert_super(x);
        insert_sub(x);
    }

    while(q--){
        cin>>x;
        if(supermask[x] or submask[x])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
