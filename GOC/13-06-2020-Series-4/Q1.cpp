/*Q1: Binary Logic
Given a number X in its binary representation find out if its divisible by a given number k
input: first line contains 2 integers n and k, denoting the length of binary representaion and
the number k as mentioned in the problem statement.
The next line contains a string of length n consisting of 0's and 1's which is binary representation of x

print "Yes" is x is divisible by k else "No"
sample input: 5 3
01001

output: Yes
given string is the binary representaion of 9. since 9 is div by 3 hence our answer is "Yes".
(Note that input string may contain leading zeroes).*/

#include<bits/stdc++.h>
#include <string>
#define ll long long int
using namespace std;


int main() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll rem=0;
    for(ll i=0;i<n;i++){
        char num=s[i];
        if(num=='1'){
            rem=(rem*2+1)%k;
        }
        else{
            rem=(rem*2)%k;
        }

    }
    if(rem%k==0) cout<<"Yes \n";
    else cout<<"No \n";

}
