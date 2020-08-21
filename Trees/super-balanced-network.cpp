/*
There is a computer network connected in a Binary tree-like structure. You as a network engineer want to connect any of the leaf computers with all other leaf computers with wlan wires. It is not possible to connect two leaf computer if the difference between their depth from the root is greater than 1. You need to tell your Boss whether it is possible to connect any of the leaf computers with all other leaf computers.

Note that, if the network contains only one leaf computer then you don't need to connect it. That is, the output will be "YES"

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the network as described below: 

The values in the string are in the order of level order traversal of the network where, numbers denotes computers, and a character “N” denotes NULL child.
Output:
For each test case, print "Yes" (without quotes) if above mentioned connection is possible otherwise, print "No" (without quotes) in new line.
Your Task:
Your task is to complete the function isPossible() which takes root pointer as parameter and returns boolean value.
Constraints:
1 <= T <= 100
1 <= Number of computers <= 10000
Example:
Input:
2
1 2 3 4 5 6 7
1 2 3 4 5 N N 6
Output:
Yes
No

Explanation:
Test Case 1:                                            1
                                                     /      \
                                                   2         3
                                                 /    \     /   \
                                               4     5      6    7
All leaf computers are at same level.
Test Case 2:                                                1
                                                          /   \
                                                         2     3
                                                       /   \
                                                      4     5
                                                     /
                                                    6
Leaf computers are 3, 5 & 6 and their depths are 2, 3 and 4 respectively and (4-2)=2 > 1.

*/
/*
    root: current node
    depth: depth of current node from actual root
    minDepth: stores minimum depth
    maxDepth: stores maximum depth 
*/

void isSuperBalancedUtil(Node *root, int depth, int &minDepth, int &maxDepth) {
    // base case 
    // if current node is null
    if (!root)
        return;
    // if leaf calculate min depth and max depth
    if (!root->left && !root->right) {
        minDepth = min(minDepth, depth);
        maxDepth = max(maxDepth, depth);
        return;
    }
    // recur for left and right subtree
    isSuperBalancedUtil(root->left, depth + 1, minDepth, maxDepth);
    isSuperBalancedUtil(root->right, depth + 1, minDepth, maxDepth);
}

bool isPossible(Node *root) {
    // initialize mindepth and maxdepth
    int minDepth = INT_MAX, maxDepth = INT_MIN;
    // utility function to calculate mindepth and max depth
    isSuperBalancedUtil(root, 1, minDepth, maxDepth);
    // checking if absolute difference of maxdepth and mindepth is less than or equal to 1
    // if yes then return true otherwise false
    if (abs(maxDepth - minDepth) <= 1)
        return true;
    return false;
}
