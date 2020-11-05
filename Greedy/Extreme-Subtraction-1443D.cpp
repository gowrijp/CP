// https://codeforces.com/contest/1443/problem/D

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int t; cin>>t;
	while (t--) {
	    int n; cin>>n; 
	    ll m = 0;
	    ll a[n];
		for (int i=0; i<n; i++) cin>>a[i];
 
		for (int i=1; i<n; i++) {
			if (a[i] < a[i-1]) m += a[i-1] - a[i];
		}
		cout<<(a[0] >= m ? "YES" : "NO")<<endl;
	}
}
