/*
https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
*/
int Solution::solve(vector<string> &A) {
    vector<double> arr;
    for(auto s : A){
        arr.push_back(stod(s));
    }
    double a=arr[0],b=arr[1],c=arr[2];
    for(int i=3;i<A.size()+1;i++){
        double sum=a+b+c;
        if(sum>1 && sum<2){
            return 1;
        }
        if(i>=A.size()){
            break;
        }
        double m=sum>2?max(a,max(b,c)):sum<1?min(a,min(b,c)):-1;
        if(a==m) a=arr[i];
        else if(b==m) b=arr[i];
        else if(c==m) c=arr[i];
    }
    return 0;
}

