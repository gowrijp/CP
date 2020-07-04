/*Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.*/

int Solution::uniquePathsWithObstacles(vector<vector<int>> &A){
  int m = A.size();
  int n = A[0].size();
  int uniquepaths[m][n];
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      uniquepaths[i][j]=0;
      if(A[i][j]) continue;
      if(i==0 && j==0) uniquepaths[i][j]=1;
      if(i>0) uniquepaths[i][j]+=uniquepaths[i-1][j];
      if(j>0) uniquepaths[i][j]+=uniquepaths[i][j-1];
    }
  }
  return uniquepaths[m-1][n-1];

}





}
