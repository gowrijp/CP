/* https://www.codechef.com/COOK120B/problems/BOJACK
Simple trick for d=1 aba; d=2 aabaa; and so on;
for string "aba" distinct substrings are a, b, ab, ba, aba = 5
for string "aba" palindromes are a, a, b, aba = 4 
so diff d = 5-4 = 1

Similarly for aabaa : distinct substrings = 11 ; palindromes : 9  diff = 2 
*/

#include <bits/stdc++.h>
#define ll long long int
#define fastIO ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main() {
	// your code goes here
	fastIO;
	int t;cin>>t;
	while(t--){
	    int d;cin>>d;
	    int n=2*d+1;
	    cout<<n<<endl;
	    for(int i=0;i<n;i++){
	        if(i==d) cout<<'b';
	        else cout<<'a';
	    }
	    cout<<endl;
	}
	return 0;
}
