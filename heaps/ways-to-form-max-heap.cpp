/*Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes.

Find the number of distinct Max Heap can be made from A distinct integers.

In short, you have to ensure the following properties for the max heap :

Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
Every node is greater than all its children.
NOTE: If you want to know more about Heaps, please visit this link. Return your answer modulo 109 + 7.

Problem Constraints
1 <= A <= 100

Input Format
First and only argument is an inetegr A.
Output Format
Return an integer denoting the number of distinct Max Heap.

Example Input
Input 1:
    A = 4  output = 3
Input 2:
    A = 10  output = 3360

Example Explanation
Explanation 1:

 Let us take 1, 2, 3, 4 as our 4 distinct integers
 Following are the 3 possible max heaps from these 4 numbers :
      4           4                     4
    /  \         / \                   / \ 
   3    2   ,   2   3      and        3   1
  /            /                     /

 1            1                     2
Explanation 2:

 Number of distinct heaps possible with 10 distinct integers = 3360.
 
Solution Approach

The root of an n-ary heap is always the maximum. The two subtrees hanging off the root are again maxheaps. 
Their size depends on n, is a bit tedious to compute the sizes n1,n2 but clearly n1+n2=n−1. We can now pick, 
which elements go to the left heap and which go to the right heap. There are (n−1)C(n1)- combinations, ways how to distribute the elements. 
This gives the recurrence

a(n)=(n−1)C(n1)*a(n1)*a(n2)

This can be solved using recursion
*/

int closest(int n){         // this function finds the height of the BST formed
    long long int m = 0;
    long long int s = 1;
    while(n != 1){
        n = n / 2;
        m++;
    }
    return m;
}
long long int combination(int n,int r,int mod){  // finds (n)C(r)
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }
    return C[r];
}
int solve(int A) {
    if(A == 0){
        return 1;
    }
    else if(A == 1){
        return 1;
    }
    else{
        int k = closest(A);                 // k is the height of BST
        int M = 1 + A - pow(2,k);           // M denotes number of nodes present in the last level(bottom-most)
        int p = pow(2,k-1);                 // p is number of nodes in the second last level - i.e. the completely filled last level
        int l = p - 1 + min(p,M);           // number of nodes in the left tree
        int r = p - 1 + max(0,M-p);         // number of nodes in the right tree
        long long int x = combination(A-1,l,1000000007);    // choosing l nodes for the left max heap from n-1 rem nodes  
        long long int y = solve(l);
        long long int z = solve(r);
        return (((x*y) % 1000000007)* z) % 1000000007;    //recursion : (n-1)C(l)*solve(l)*solve(r)
    }
}

