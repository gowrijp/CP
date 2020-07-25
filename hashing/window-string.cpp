/*Given a string S and a string T, find the minimum window in S which will contain all 
the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window 
in S should be at least N.
eg:
S = "ADOBECODEBANC"
T = "ABC"
here min window is BANC

If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).
*/

#include<bits/stdc++.h>
using namespace std;

string minWindow(string A, string B) {
  vector<int> m(128, 0);
  for (char c : B) 
      m[c]++;                   //m->a=1,b=1,c=1

int remaining = B.length();     //remaining = 3
int left = 0, right = 0, minStart = 0, minLen =INT_MAX; //numeric_limits<int>::max() is same as INT_MAX;

while (right < A.length()){
    if (--m[A[right++]] >= 0) 
        remaining--;
    
    while (remaining == 0){
        if (right - left < minLen){
            minLen = right - left;
            minStart = left;
        }
        if (++m[A[left++]] > 0) 
            remaining++;
    }
}
    
return minLen < INT_MAX ? A.substr(minStart, minLen) : "";
}

int main(){
    string A="ADOBECODEBANC";
    string B="ABC";
    cout<<minWindow(A,B)<<endl;
}