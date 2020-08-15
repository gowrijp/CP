/*
https://www.hackerrank.com/contests/goc-cdc-series-8/challenges/preventing-an-apocalypse/editorial

In the world of magic, to make sure that you don't use your powers without consequences, we have something called as Mana. Casting a spell costs Mana points and as long as you have enough, you can cast spells. As for you, you are a local Warlock. Most of you spells don't do much, but your existence becomes crucial when the world is at brink of extinction. One such scenario is now.

A Celestial Mage tell you about an incoming asteriod that you need to deflect. To do so, you have to create N consequtive pillars, each pillar can be made of Quas(Ice), Wex(Strom) or Exort(Fire) elements. You however need to remember that two adjacent pillars cannot be the same for stability purposes.
The Mana cost of making a Quas, Wex, or Exort pillar at location i is Qi, Wi, and Ei respectively. Lately you have been running into some Mana issues so you have to minimize the amount of Mana you expend. Can you calculate the same in advance?

Input Format

The first line contains a single integer N  denoting the number of pillars you have to make.

N lines follow, each of the ith line contains three space separated intergers Qi, Wi, and Ei denoting the Mana cost for creating a pillar of the specified type.
Output Format

Output a single integer denoting the Minimum required Mana cost to complete the entire structure.

Sample Input 0

3
1 2 3
4 5 6
7 8 9
Sample Output 0

13
Explanation 0

You first choose a Quas element having a cost 1 at location 1. Then at location 2 you pick a Wex element with cost 5. Notice that it would have been cheaper to pick a Quas element again but then it would rendered the structure Unstable. At the final location you pick Quas again to end up with a total cost of 13.

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long dp[n][3];
    int q,w,e;
    cin>>q>>w>>e;
    dp[0][0]=q;
    dp[0][1]=w;
    dp[0][2]=e;
    for(int i=1;i<n;i++)
    {
        cin>>q>>w>>e;
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+q;
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+w;
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+e;
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
    return 0;
}
