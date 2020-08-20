/*
https://codeforces.com/problemset/problem/1307/C

SOLUTION
We observe that if the hidden string that occurs the most times has length longer than 2, then there must exist one that occurs just as many times of length exactly 2. 
This is true because we can always just take the first 2 letters; there can't be any collisions. Therefore, we only need to check strings of lengths 1 and 2. Checking strings 
of length 1 is easy. To check strings of length 2, we can iterate across S from left to right and update the number of times we have seen each string of length 1 and 2 using DP.

Time Complexity: O(|s|c) (c is length of alphabet)
*/

#include <iostream>
using namespace std;

typedef long long ll;
ll arr1[26],arr2[26][26];

int main(){
  string S;
  cin>>S;
  for (int i=0;i<S.length();i++){
    int c=S[i]-'a';
    for (int j=0;j<26;j++)
      arr2[j][c]+=arr1[j];
    arr1[c]++;
  }
  ll ans=0;
  for (int i=0;i<26;i++)
    ans=max(ans,arr1[i]);
  for (int i=0;i<26;i++)
    for (int j=0;j<26;j++)
      ans=max(ans,arr2[i][j]);
  cout<<ans<<endl;
}
