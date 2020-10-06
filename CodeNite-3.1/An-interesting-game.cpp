/*
There is a number N, Tanmay and Kush are playing a game against each other. The two players perform the following operation alternately, starting from Tanmay:

write N as binary number and in one turn you can convert any set bit to 0 and you can convert any length substring (including 0) of 0s just preceding that bit i.e. to the right of the resetted bit to 1s.
For ex - 1000 can be converted to 0000,0100,0110,0111.
A player loses when he becomes unable to play. Assuming that both players play optimally, determine the winner.

Input Format:   First line contains the number of test cases.
                T line follows and in every line you have been given original number N before the starting of game.

Constraints
1<=T<=100000.
0<=N<=100000.

Output Format
You have to output a string containing the name of the player who is winning for every test case in a new line.

Sample Input 0
3
1
2
4
Sample Output 0
Tanmay
Tanmay
Tanmay
Explanation 0
if N = 1 then Tanmay will remove 1 and then Kush will not be able to perform any operation. if N = 2 then it's binary equivalent is (10) now Tanmay can remove 1 and choose the length of substring as 0 therefore the resulting number will be 0 hence Kush will not be able to perform any operation and Tanmay will win
Similarly for 4 binary eqv is 100 and Tanmay will remove the 1 and choose length of substring as 0 and hence Kuch wont be able to perform any more operations
*/

/*
Observation - Claim: "if N%3=0 then the second player wins otherwise always the first player wins."

This can be proved by principle of induction.We can see that if N=0 then first player loses ,for N=1 or 2 first player always wins. Let's say the following assumption is true till k such that k%3=0.

Let’s take k+1,so (k+1)%3=1 first player can remove 1 from N .We know that for k the first player always loses ,as in this case second player will be the first player so he will lose and in this way for k+1 first player wins .

Similarly for k+2 first player can take out 2 and win.

For k+3 we can see that as no [power of 2] (mod) 3 equals 0 as (k+3)%3=0 ,this implies (k+3-2^x)%3 !=0 .Thus first player will always lose in this case. Hence our claim is true.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        if(n%3==0) cout<<"Kush"<<"\n";
        else cout<<"Tanmay"<<"\n";
    }
    return 0;
}
