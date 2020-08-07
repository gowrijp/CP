/*
https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.
Input 1:

       1
      / \
     2   3

Output 1:
     6

Explanation 1:
    The path with maximum sum is: 2 -> 1 -> 3

Input 2:
    
       -10
       /  \
     -20  -30

Output 2:
    -10

Explanation 2
    The path with maximum sum is: -10
*/

int ans;
int solve(TreeNode* curr){
    if(curr==nullptr)
        return 0;
    int ansL = solve(curr->left);
    int ansR = solve(curr->right);
    ansL = max(ansL, 0);
    ansR = max(ansR, 0);
    ans = max(curr->val + ansL + ansR, ans);
    int retV =  max(ansL, ansR)>0? max(ansL, ansR):0;
    retV+=curr->val;
    return retV;
} 
int Solution::maxPathSum(TreeNode* A) {
    if(A==nullptr)
        return 0;
    ans = A->val;
    solve(A);
    return ans;
}
