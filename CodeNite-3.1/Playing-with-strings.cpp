/*
Kushagra is fond of prefixes in a string while Tanmay likes suffixes more.One day they decided to find all the prefixes which are suffixes of a string.As finding all such substrings was tedious they decided they will only find the number of such occurrences.Can you help them to find the number of prefixes which are also the suffix of the given string .
Note Prefix of string s of length k is s[1],s[2].....s[k] and suffix of given string of length k is s[n-k+1],s[n-k+2]......s[n]

Input Format:  A string s of length n

Constraints:  1<= |s| <1000000

Output Format:  Number of prefixes which are also the suffix of the given string

Sample Input 0 :   aba
Sample Output 0:   2
Explanation 0:   Required prefixs are a,aba

Sample Input 1:   aaa
Sample Output 1:   3
Explanation 1

Required prefixes are a,aa,aaa
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int l =s.size();
    int count=0;
    for(int i=l;i--;){
        string s1=s.substr(0,i);
        string s2=s.substr(l-i,i);
        if(s1==s2) count++;
    }
    cout<<count<<"\n";
    return 0;
}

