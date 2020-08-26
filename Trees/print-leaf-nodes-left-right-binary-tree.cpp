/*
https://www.geeksforgeeks.org/print-leaf-nodes-left-right-binary-tree/
*/

void printLeafNodes(Node *root) 
{ 
    // if node is null, return 
    if (!root) 
        return; 
      
    // if node is leaf node, print its data     
    if (!root->left && !root->right) 
    { 
        cout << root->data << " ";  
        return; 
    } 
  
    // if left child exists, check for leaf  
    // recursively 
    if (root->left) 
       printLeafNodes(root->left); 
          
    // if right child exists, check for leaf  
    // recursively 
    if (root->right) 
       printLeafNodes(root->right); 
} 
