#include <bits/stdc++.h> 
using namespace std; 
  
#define R 4 
#define C 4 
  
// Function for printing matrix in spiral 
// form i, j: Start index of matrix, row  
// and column respectively m, n: End index 
// of matrix row and column respectively 

vector<int> ans;

void myfunc(vector<vector<int>> &arr, int i, int j, int m, int n) { 
    // If i or j lies outside the matrix 
    if (i >= m or j >= n) 
        return;
  
    // Print First Row 
    for (int p = i; p < n; p++) 
        ans.push_back(arr[i][p]); 
  
    // Print Last Column 
    for (int p = i + 1; p < m; p++) 
        ans.push_back(arr[p][n - 1]); 
  
    // Print Last Row, if Last and 
    // First Row are not same 
    if ((m - 1) != i) 
        for (int p = n - 2; p >= j; p--) 
            ans.push_back(arr[m - 1][p]); 
  
    // Print First Column,  if Last and 
    // First Column are not same 
    if ((n - 1) != j) 
        for (int p = m - 2; p > i; p--) 
            ans.push_back(arr[p][j]);
  
    myfunc(arr, i + 1, j + 1, m - 1, n - 1); 
} 
  
// Driver Program 
int main() 
{ 
  
    vector<vector<int>> arr = { { 1, 2, 3, 4 }, 
                    { 5, 6, 7, 8 }, 
                    { 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16 } }; 
  
    myfunc(arr, 0, 0, R, C); 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
} 