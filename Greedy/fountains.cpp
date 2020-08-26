/*
https://leetcode.com/discuss/interview-question/363036/twitter-oa-2019-activate-fountain

Given a 1-D garden of length n . At each position a fountain has been installed. The fountain at ith position has a value a[i] which describes the coverage limit of the fountain i.
*/

#include <bits/stdc++.h>
using namespace std;

int numFountains(vector<int> fountains) {
    int n = fountains.size();
    vector<int> extents(n, 0);

    for (int i = 0; i < n; i++) {
        int left = max(i - fountains[i], 0);
        int right = min(i + (fountains[i] + 1), n);
        extents[left] = max(extents[left], right);
    }

    int num_fountains = 1;
    int right = extents[0], next_right = 0;
    for (int i = 0; i < n; i++) {
        next_right = max(next_right, extents[i]);
        if (i == right) {
            num_fountains++;
            right = next_right;
        }
    }

    return num_fountains;
}

int main()
{
    vector<int> arr= {0,0,0,3,0,0,2,0,0};
    int ans=numFountains(arr);
    cout<<ans<<endl;
    return 0;
}
