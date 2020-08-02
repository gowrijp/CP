#include<bits/stdc++.h> 
using namespace std; 
  
  
// Given a number as a string, this function finds the 
// next greater number.  It modifies the same array to store the result 
string findNext(string s) 
{ 
    int i, j; 
    int n=s.size();
    // I) Start from the right most digit and find the first digit that is 
    // smaller than the digit next to it. 
    for (i = n-1; i > 0; i--) 
        if (s[i] > s[i-1]) 
           break; 
  
    // If no such digit is found, then all digits are in descending order 
    // means there cannot be a greater number with same set of digits 
    if (i==0) 
    { 
        return "-1"; 
    } 
  
    // II) Find the smallest digit on right side of (i-1)'th digit that is 
    // greater than number[i-1] 
    int x = s[i-1], smallest = i; 
    for (j = i+1; j < n; j++) 
        if (s[j] > x && s[j] < s[smallest]) 
            smallest = j; 
  
    // III) Swap the above found smallest digit with number[i-1] 
    swap(s[smallest], s[i-1]); 
  
    // IV) Sort the digits after (i-1) in ascending order 
    sort(s.begin()+ i, s.end()); 
  
    return s;
} 
  
// Driver program to test above function 
int main() 
{ 
    string s = "534976";   //"4321";
    cout<<findNext(s); 
    
} 