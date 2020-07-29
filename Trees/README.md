## 1 - Binary Search Tree
- It is a node-based binary tree data structure which has the following properties:
- The left subtree of a node contains only nodes with keys lesser than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.

```
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```
### Getting all valued from a Binary Search tree in sorted order in a vector and deleting the nodes traversed from the tree
```
// vector<int> num will have all the values from the tree in ascending order

void recurse(TreeNode* cur, vector<int>& num) {
    if(cur == NULL) {
        return;
    }
    recurse(cur->left, num);
    num.push_back(cur->val);
    recurse(cur->right, num);
    delete cur;
 }
```
