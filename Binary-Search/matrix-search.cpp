/*
https://www.interviewbit.com/problems/matrix-search/

*/

int binarysearch(vector<int> &arr,int start,int end,int check){
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==check) return 1;
        else if(arr[mid]>check){
            end=mid-1;
        }
        else start=mid+1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int startr=0;
    int endr = A.size()-1;
    int startcol=0;
    int endcol = A[0].size()-1;
    
    while(startr<=endr){
        int midr = (startr+endr)/2;
        if(A[midr][0]==B) return 1;
        else if(A[midr][0]<B && B<=A[midr][endcol]){
            //Binary search midr row
            int ans = binarysearch(A[midr],0,endcol,B);
            return ans;
        }
        else if(A[midr][0]<B){
            startr=midr+1;
        }
        else endr=midr-1;
    }
    return 0;
}
