/*
https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
*/

vector<int> Solution::getRow(int k){
    vector<int> ret(k+1, 0);
    ret[0]=1;
    vector<int> temp(k+1, 0);
    temp[0] = 1, temp[1]=1;
    for(int i=1; i<=k; i++){
        for(int j=1; j<i; j++){
            ret[j] = temp[j] + temp[j-1];
        }
        ret[i] = 1;
        temp = ret;
    }
    return ret;
}
