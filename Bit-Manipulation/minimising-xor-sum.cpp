// https://www.geeksforgeeks.org/choose-x-such-that-a-xor-x-b-xor-x-is-minimized/
// https://codeforces.com/contest/1421/problem/A

#include<bits/stdc++.h>
using namespace std; 

int findX(int A, int B) { 
    int j = 0, x = 0; 
    // While either A or B is non-zero 
    while (A || B) { 
        if ((A & 1) && (B & 1)) { 
            // Inserting a set bit in x 
            x += (1 << j); 
        } 
        // Left shifting both numbers to traverse all the bits 
        A >>= 1; 
        B >>= 1; 
        j += 1; 
    } 
    return x; 
} 
  
 
int main() { 
    int t; cin>>t;
    while(t--){
        int A,B; cin>>A>>B;
        int X=findX(A,B);
        cout<<(A^X)+(B^X)<<"\n";
    }
    return 0; 
} 
