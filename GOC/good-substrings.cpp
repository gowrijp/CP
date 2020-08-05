/*
A binary string is a string which contains only 0s and 1s. A binary string is called a good string if it contains equal number of 0s and 1s and the all the 0s and 1s are 
contiguous. For instance 0011,01,1100,111000,000111 are good binary strings. However 0101,110010 are not because even though they contain equal number of 0s and 1s but the 
0s and 1s are not together. A substring of a string is a contiguous subsequence of that string. So, string "forces" is substring of string "codeforces", but string "coder" is 
not. You are given a binary string S of length N , You need to find the number of good substrings of the given string.

Input Format
Number Of Test Cases
For Each Test Case
N(Length of the string)
S(Input String)

Sample Input 0
2
6
001101
2
01

Sample Output 0
4
1

Explanation: For the first test case there are 4 good substrings 01,0011,10 and 01.Similarly the second test case only contains one good substring 01.

// FIRST ANS (TLE) 
#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    int t;cin>>t;
    //int t=1;
    while(t--){
        int n;
        cin>>n;
        string inp;
        //cout<<inp<<endl;
        cin>>inp;
        int count=0;
        for(int i=1;i<=n/2;i++){
            string s="";
            s.append(string(i,'0'));
            s.append(string(i,'1'));
            //cout<<s<<endl;
            string inv="";
            inv.append(string(i,'1'));
            inv.append(string(i,'0'));
            //cout<<inv<<endl;
            for(int j=0;j<=n-2*i;j++){
                if(inp.substr(j,2*i)==s || inp.substr(j,2*i)==inv){
                   count++; 
                } 
            }
        }
        cout<<count<<endl;
    }
    
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MAIN SOLUTION APPROACH 

If we carefully observe then there can be only one possible good substring ending at a given position. WLOG let us assume that the current character is 1. So we need the 
number of contiguous 1's just preceding the current position and the number of contiguous 0's just preceding the chain of 1's. If the length of the chain of zeroes is greater 
than or equal to the length of the chain of 1's then we can have a good substring ending at the current position. This can be implemented just by two counters in O(N) time 
as shown below in the code.

*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int res = 0;
        int ones = 0;
        int zeroes = 0;
        if (s[0] == '0')
            zeroes++;
        else
            ones++;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                if (s[i] == '1')
                {
                    ones++;
                    if (zeroes >= ones)
                        res++;
                }
                else
                {
                    zeroes++;
                    if (ones >= zeroes)
                        res++;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    ones = 1;
                    if (zeroes >= ones)
                        res++;


                }
                else
                {
                    zeroes = 1;
                    if (ones >= zeroes)
                        res++;

                }

            }
        }
        cout<<res<<endl;
    }
    time();
    return 0;
}



