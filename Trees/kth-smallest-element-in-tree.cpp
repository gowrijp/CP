/*Given a binary search tree, write a function to find the kth smallest element in the tree.
Example :
Input : 
  2
 / \
1   3

and k = 2
Return : 2
As 2 is the second smallest element in the tree.*/

#include<bits/stdc++.h>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

priority_queue<int, vector<int>, greater<int> > pq;

void dfs(TreeNode* root){
    if(!root) return;
    pq.push(root->val);
    dfs(root->right);
    dfs(root->left);
}
int kthsmallest(TreeNode* root, int B) {
    pq = priority_queue<int, vector<int> , greater<int> >();
    if(root==NULL) return 0;
    dfs(root);
    for(int i=1;i<B;i++)
        pq.pop();
        
    return pq.top();
}

