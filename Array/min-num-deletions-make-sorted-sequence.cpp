/*
https://www.geeksforgeeks.org/minimum-number-deletions-make-sorted-sequence/

SOLUTION: An efficient approach uses the concept of finding the length of the longest increasing subsequence of a given sequence.
-->arr be the given array.
-->n number of elements in arr.
-->len be the length of longest
   increasing subsequence in arr.
-->// minimum number of deletions
   min = n - len
*/

int lis( int arr[], int n ) 
{ 
    int result = 0; 
    vector<int> lis(n,1);
  
    for (int i = 1; i < n; i++ ) 
        for (int j = 0; j < i; j++ ) 
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1){ 
                lis[i] = lis[j] + 1; 
                result=max(result, lis[i]);
            }
  
    return result; 
} 
