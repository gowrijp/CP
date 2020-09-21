/*Q6: Number Theory problem
This is one of the questions in project euler called diophantine reciprocals ii
find number of ordered pair of positive integral solutions of a sum 1/x + 1/y = 1/n
The only line of input contains a single integer n

eg: 5
Ans: 3
ordered pairs (6,30); (30,6); (10,10) satisfy

note the handling of the largest prime divisor */

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAX = 1000000000;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n; cin>>n;
    ll divCount = 1;
    for(ll i = 2; i * i <= n; ++i)if(n%i == 0){
        ll pw = 0;         // maximum power
        while(n%i == 0)n/= i, pw++;

        divCount *= (2*pw + 1);
    }
    if(n > 1)divCount *= (2*1 + 1); // largest prime divisor.
    cout<<divCount<<"\n";
    return 0;
}
