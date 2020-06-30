/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).*/

int Solution::minimumTotal(vector<vector<int>> &a){
  for(int i=a.size()-2;i>=0;i--){
    for(int j=0;j<a[i].size();j++){
      a[i][j] = min(a[i+1][j],a[i+1][j+1])+a[i][j];
    }
  }
  return a[0][0];
}
