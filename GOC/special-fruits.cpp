/*
https://www.hackerrank.com/contests/goc-cdc-series-5/challenges/special-fruits

There are N different special fruits in our country and infinite villages, as farmers in the country are lazy they distribute the fruits only in nearest (X) villages i.e farmer 
in village V will distribute from village index (V-X) to village index (V+X).(where X varies with farmers). Only the fruit farmer is allowed to sell their own fruit.You are 
given a task by the government to collect all the special fruits. Find the minimum number of villages you will have to visit to collect all varieties of special fruits, also 
you need to specify which villages you are planning on visiting.

Input Format
Number of Test Cases T
For Each Test Case
N (Number of Farmers)
(V, X) tuple for each Farmer

Constraints
-10^18 <= V <= 10^18
0 <= X <= 10^18
Villages with Negative indices exists.

Output Format
For Each Test Case
Minimum number of villages to visit.
The Village's indices you will visit. (You can print in any order)

Sample Input 0

1
3
3 2
4 3
5 1

Sample Output 0

1
4

Explanation 0
Just Visiting village 4 should suffice
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION

Problem Essentially is: Given n line segments [li, ri], find the minimum number of integral points to be chosen, such that each line segment [li, ri] contains a chosen point.
Short Solution: Sort According to end points. Take the leftmost end point. Iterate over the Segments take the new segments end point if the interval is not covered yet.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define trav(a, x) for (auto& a : x)
#define F first
#define S second

int32_t main() {
  int t;
  // freopen("input.txt", "r", stdin);    // redirects standard input
  // freopen("output.txt", "w", stdout);  // redirects standard output
  cin >> t;
  while (t--) {
    int n, t1, t2, t3, t4;
    cin >> n;
    vector<pair<int, int>> segments(n);
    trav(it, segments) cin >> it.F >> it.S, t1 = it.F - it.S, t2 = it.F + it.S,
                                            it.F = t2, it.S = t1;
    vector<int> ans;
    sort(segments.begin(), segments.end());
    // reverse(segments.begin(), segments.end());
    ans.push_back(segments[0].F);
    trav(it, segments) {
      if (it.F >= ans.back() and it.S <= ans.back()) {
        continue;
      }
      ans.push_back(it.F);
    }
    cout << (int)(ans.size()) << endl;
    trav(it, ans) cout << it << " ";
    cout << endl;
  }
}
