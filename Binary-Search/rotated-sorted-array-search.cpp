/*
https://www.interviewbit.com/problems/rotated-sorted-array-search/
*/

int fn(vector< int> A,int B,int l,int h){
    while(l<=h){
        int mid=(l+h)/2;
        if(A[mid]==B) return mid;
        if(A[mid]>A[l]){
            if(A[mid]>B && A[l]<=B) h=mid-1;
            else l=mid+1;
        }
        else{
            if(A[mid]<B && A[h]>=B) l=mid+1;
            else h=mid-1;
        }
    }
    return -1;
}
int Solution::search(const vector< int> &A, int B) {
    int n=A.size();
    int y=fn(A,B,0,n-1);
    return y;
}
