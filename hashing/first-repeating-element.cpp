/*
https://www.interviewbit.com/problems/first-repeating-element/

*/
int Solution::solve(vector<int> &A) {
    map<int,int> mp;
    int n=A.size();
    int ans=INT_MAX;
    int fin=0;
    for(int i=0;i<n;i++){
        if(mp.find(A[i])==mp.end()){
            mp[A[i]]=i;
        }
        else{
            if(mp[A[i]]<ans){
               fin=A[i];
               ans=mp[A[i]];
            } 
        }
    }
    if(ans==INT_MAX) return -1;
    else return fin;
}
