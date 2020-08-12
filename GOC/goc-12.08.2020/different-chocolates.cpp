/*
There are N different varieties of Chocolates with different levels of Milk in it. Mike loves Chocolates with greater Milk content and will try to maximize the same.

There are infinte amount of chocolates of all varieties.

He is given the N different choclates in the Order C[1], C[2], .. , C[N], where C[i] is the Milk level. Mike being a greedy person selects the chocolate with maximum Milk content he saw till now. For Ex: if he gets 2, 1, 3 Milk level chocolate he First selects 2 , then selects 2 , then selects 3. So the Chocolate's he has will have 2, 2, 3 milk level so Distinct number of Chocolates will be 2 which are [2, 3].

You are asked by Mike to calculate how many Expected number of distinct chocolate's he would have given the varieties but not the order, considering any order is equally likely.

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains an Integer N.
The second line contains N distinct integers A[1], A[2], ..., A[n] varieties of Milk NOT in order. Any Permutation is equally likely. A is permuted to make C where each permutation is equally likely.
Constraints

1 <= T <= 20
1 <= N <= 100000
1 <= A[i] <= 1000000000
MOD = 1000000007
A[i] != A[j] for all i != j pairs.
Output Format

Suppose the Expected number of distinct chocolate is of form P/Q. Output Integer (P*(Q^(-1)))%MOD. What is Q^(-1)%MOD.
Sample Input 0

1
2
1 2
Sample Output 0

500000005
Explanation 0

Permutations of [1,2] -> [[2, 1], [1, 2]] which will lead to [[2, 2], [1, 2]]

Different Choclates are [1, 2] so Expected = (1 + 2)/2! = (3/2).

P = 3, Q = 2.

SOLUTION EXP:
By Linearity Expectations we have ith element to be different from (i-1)th iff ith is the greatest element amongst A[0],.. A[i]. Probability of that being the case = 1/i. 
So Number of Distinct element = 1/1 + 1/2 + 1/3 + ... + 1/n.

Note: All Can be precalculated for all the Test Cases and Note the A[i] values doesn't matter.
*/

#include <stdio.h>
const int Mod = 1000000007;

const int N = 100009;

int invMod[100009];
int ans[100009];

long long int t1, t2, t3, t4;

int binpow(int a, int b) {
  if (b == 0)
    return 1;
  t2 = binpow(a, b / 2);
  t2 *= t2;
  t2 %= Mod;
  if (b % 2)
    t2 *= a;
  t2 %= Mod;
  return (int)t2;
}

int inverseMod(int a) {
  return binpow(a, Mod - 2);
}

void pre() {
  ans[1] = 1;
  for (int i = 2; i < N; i++) {
    invMod[i] = inverseMod(i);
    ans[i] = ans[i - 1];
    ans[i] += invMod[i];
    ans[i] %= Mod;
  }
}

int main() {
  pre();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, t5;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &t5);
    }
    printf("%d\n", ans[n]);
  }
}

