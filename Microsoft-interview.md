## Questions 

- Check is a Binary Tree is a BST or not  
BST : For any node its left subtree should have nodes lesser in value than the node and the right subtree should have nodes with values larger than the node. So we define the range of every node. 
Root Node can take any value- range(-infinity to inf) ; left node value range(-inf, root node value) ; right node value (root node, inf)  
<br>

- Clone a doubly linked list which has a next and an arbitrary(random) pointer    
https://www.youtube.com/watch?v=SsmNI3Mlp0I (from 1:56)  
![alt text](https://github.com/gowrijp/CP/blob/master/Images/Screenshot%20(58).png)
 
 ```
 For this first simply clone all the nodes in a new linked list with only the next pointers
 Now point the next pointer of all nodes in the original list to their corresponding nodes in the copy list
 Then for each node in the copy list point its red pointer to the corresponding node pointed by that red pointer in the original list
 Finally in the copy list point each nodes red pointer to its immediate next node 
 ```
 - Connect nodes at the same level in a binary tree  
 Use level order traversal with a little modification
 
