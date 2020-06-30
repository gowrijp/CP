/*Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/
void fun(vector<int> &A,int start,int end,string soln){
    soln+=to_string(A[start])+" ";
    if (start == end-1)return;
    for (int i=start+1;i<end;i++){
        cout<<soln<<A[i]<<" ] ";
        fun(A,i,end,soln);
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    cout<<"[] ";
    for (int i=0;i<A.size();i++){
        cout<<"["<<A[i]<<" ] ";
        fun(A,i,A.size(),"[");
    }
    vector<vector<int>> a;
    return a;
}
