#include<bits/stdc++.h>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recurse(TreeNode* cur, vector<int>& num) {
    if(cur == NULL) {
        return;
    }
    recurse(cur->left, num);
    num.push_back(cur->val);
    recurse(cur->right, num);
    delete cur;
 }
 
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> num;
    recurse(A, num);
    int low=0, high=num.size()-1;
    while(low < high) {
        if(num[low]+num[high] > B) {
            high--;
        } else if(num[low] + num[high] < B) {
            low++;
        } else {
            return 1;
        }
    }
    return 0;
}