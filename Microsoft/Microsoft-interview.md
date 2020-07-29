## Questions 
### https://www.geeksforgeeks.org/microsofts-asked-interview-questions/

- <b>Ques 1</b> Check is a Binary Tree is a BST or not  
BST : For any node its left subtree should have nodes lesser in value than the node and the right subtree should have nodes with values larger than the node. So we define the range of every node. 
Root Node can take any value- range(-infinity to inf) ; left node value range(-inf, root node value) ; right node value (root node, inf)  
<br>

- <b>Ques 2 </b>Clone a doubly linked list which has a next and an arbitrary(random) pointer    
https://www.youtube.com/watch?v=SsmNI3Mlp0I (from 1:56)  
![alt text](https://github.com/gowrijp/CP/blob/master/Images/Screenshot%20(58).png)
 
 ```
 For this first simply clone all the nodes in a new linked list with only the next pointers
 Now point the next pointer of all nodes in the original list to their corresponding nodes in the copy list
 Then for each node in the copy list point its red pointer to the corresponding node pointed by that red pointer in the
 original list
 Finally in the copy list point each nodes red pointer to its immediate next node 
 ```
 - <b>Ques 3 </b>Remove duplicates from a string   
 https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/  
 Method 1 
 ```
 string removeDuplicate(string str, int n) 
{ 
   // Used as index in the modified string 
   int index = 0;    
     
   // Traverse through all characters 
   for (int i=0; i<n; i++) { 
     int j;    
     // Check if str[i] is present before it   
     for (j=0; j<i; j++)  
        if (str[i] == str[j]) 
           break; 
       
     // If not present, then add it to 
     // result. 
     if (j == i) 
        str[index++] = str[i]; 
   } 
     
   return str; 
} 
```
<b>Other methods - using BST (sets)- O(nlogn) time ; Sort and then remove duplicates; Using hashing: O(n) ;   </b>

- <b>Ques 4 </b> Search an element in a sorted and rotated array  
https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
```
An element in a sorted array can be found in O(log n) time via binary search. 
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. 
So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
Devise a way to find an element in the rotated array in O(log n) time.

Solution :
The idea is to find the pivot point, divide the array in two sub-arrays and perform binary search.
The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only element for which next element to it is smaller than it.
Using the above statement and binary search pivot can be found.
After the pivot is found out divide the array in two sub-arrays.
Now the individual sub – arrays are sorted so the element can be searched using Binary Search.
```
