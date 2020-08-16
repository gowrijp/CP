/*
https://www.interviewbit.com/problems/pascal-triangle/

*/
vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    if(A==0) return ans;
    ans.push_back({1});
    if(A==1) return ans;
    int elements=2;
    for(int i=1;i<A;i++){
        vector<int> temp(elements,1);
        int st=1;
        int end=elements-2;
        while(st<=end){
            temp[st]=ans[i-1][st]+ans[i-1][st-1];
            temp[end]=temp[st];
            st++;
            end--;
        }
        ans.push_back(temp);
        elements++;
    }
    return ans;
}
