/*
https://www.hackerrank.com/challenges/non-divisible-subset/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=7-day-campaign

SOLUTION: https://www.hackerrank.com/challenges/non-divisible-subset/editorial
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m,ret,num;
    int a[100]={0};
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num;
        a[num%m]++;
    }
    if (m % 2 == 0)
        a[m / 2] = min(a[m / 2], 1);
    ret = 0;
    for(int i = 1; i <= m / 2; i++)
        ret += max(a[i], a[m - i]);
    ret += min(a[0], 1);
    cout << ret << endl;
    return 0;
}
