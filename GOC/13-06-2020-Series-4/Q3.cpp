
/*SUM AND XOR
Q queries are given, each query has 2 integers s and x. find two integers A and B such that their sum
is s and xor is x.
If there are multiple such pairs, find the one with minimum value of A
If there is no such pair return -1 -1

eg:
3
8 4
12 10
9 12

output:
2 6
1 11
-1 -1*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin>>q;
    while(q--){
        int sum, xr; cin>>sum>>xr;
        // (a^b) + 2*(a & b) = a + b => 2*(a&b) = sum - xr

        if(sum - xr < 0 || (sum - xr)%2 != 0)cout<<"-1 -1\n";
        else{
            int nd = (sum - xr)/2;

            //if a bit is set in nd -> it is set in both
            // if a bit is not set in nd but set in xr -> it is set in exactly one of (a, b)
            // (we set these bits only in b to minimize a)
            // if a bit is set in both nd nd xr => contradiction
            // thus a = nd (only set bits in nd) nd b = nd | xr (set bits in both "nd" nd "xr")
            if(nd & xr)cout<<"-1 -1\n";
            else cout<<nd<<" "<<(nd | xr)<<"\n";
        }
    }
    return 0;
}
