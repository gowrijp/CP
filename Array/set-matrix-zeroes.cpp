/*
https://www.interviewbit.com/problems/set-matrix-zeros/

*/
void Solution::setZeroes(vector<vector<int> > &A) {
    set<int> col, row;
    for(int i=0; i<A.size(); ++i) {
        for(int j=0; j<A[0].size(); ++j){
            if(A[i][j] == 0) {
                col.insert(j);
                row.insert(i);
            }
        }
    }
    for(auto c: col) {
        for(int i=0; i<A.size(); ++i){
            A[i][c] = 0;
        }
    }
    for(auto r: row) {
        for (int i=0; i< A[0].size(); ++i) {
            A[r][i] = 0;
        }
    }
}
