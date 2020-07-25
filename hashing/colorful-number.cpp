#include<bits/stdc++.h>
using namespace std;

int colorful(int A) {
    int temp=A;
    vector<int> r;
    while(temp>0){
        r.push_back(temp%10);
        temp=temp/10;
    }
    int n=r.size();
    map<int, int>hash;
    for(int i=0;i<n;i++){
        hash[r[i]]++;
        if(hash[r[i]]>1) return 0;
        int prod=r[i];
        for(int j=i+1;j<n;j++){
            prod*=r[j];
            hash[prod]++;
            if(hash[prod]>1) return 0;
        }
    }
    return 1;
    
}

int main(){
    int A=3245;
    cout<<colorful(A)<<endl;
    

}