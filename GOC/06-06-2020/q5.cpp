/*Jhul and distinct numbers-2 ------ USING SETS AND CONCEPT OF STL
Jhul has two array A and B of N integers.
He wants to create a new array containing distinct elements which are either present in A or in B(not in both).
Sample Input:
5
5 2 1 2 3
1 3 3 4 6
Sample Output:

2 4 5 6
2,5 is present in A not in B
4,6 is present in B not in A*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++)
            cin>>a[i];
    for(int i=0;i<n;i++)
            cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    int k=0;
    int l=0;
    set <ll> s1;
    while(k<n&&l<n){
        if(a[k]==b[l]){
            int j=k;
            while(j<n&&a[j]==a[k])
                j++;
            k=j;
            j=l;
            while(j<n&&b[j]==b[l])
                j++;
            l=j;
        }
        else if(a[k]<b[l]){
            s1.insert(a[k]);
            k++;
        }
        else{
            s1.insert(b[l]);
            l++;
        }
    }
    for(int i=k;i<n;i++)
        s1.insert(a[i]);
    for(int i=l;i<n;i++)
        s1.insert(b[i]);
    for(auto it=s1.begin();it!=s1.end();it++)
        cout<<(*it)<<" ";


}
