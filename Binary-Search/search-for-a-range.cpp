/*
https://www.interviewbit.com/problems/search-for-a-range/

*/
vector<int> Solution::searchRange(const vector<int> &A, int B){
    int pos1=-1,pos2=-1;
    int l=0,r=A.size()-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(A[mid]==B){
            pos1=mid;
            r=mid-1;
        }
        else if(A[mid]<B)
            l=mid+1;
        else if(A[mid]>B)
            r=mid-1;
    }
    l=0,r=A.size()-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(A[mid]==B){
            pos2=mid;
            l=mid+1;
        }
        else if(A[mid]<B)
            l=mid+1;
        else if(A[mid]>B)
            r=mid-1;
    }
    vector<int> temp;
    temp.push_back(pos1);
    temp.push_back(pos2);
    return temp;
}
