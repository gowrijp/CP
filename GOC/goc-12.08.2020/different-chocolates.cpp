/*
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

