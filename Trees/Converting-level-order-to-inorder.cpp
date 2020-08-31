/*
Question came in Morgan Stanley test

Given an array representing the level order traversal of a binary tree, convert it to inorder traversal and output the array
*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void recurse(int *inp, int size_array, int *output, int iter_a, int &iter_b)
{
    if (iter_a>=size_array)
        return;

    recurse (inp,size_array,output,2*iter_a+1,iter_b);

    output[iter_b] = inp[iter_a];
    iter_b++;

    recurse (inp,size_array,output,2*iter_a+2,iter_b);

}

int main()
{
    int arr[9]={5,6,3,4,-1,2,8,-1,1};
    int e[9];
    int iter_a=0;
    int iter_b=0;
    int n=9;
    recurse(arr,9,e,iter_a,iter_b);
    for(int i=0;i<9;i++){
        cout<<e[i]<<" ";
    }
    
    /*
    vector<int> a;
    for(int i=0;i<n;i++){
        if(e[i]!=-1){
            a.push_back(e[i]);
        }
    }
    n=a.size();
    vector<int> ans;
    ans.push_back(a[1]);
    for(int i=1;i<n-1;i++){
        ans.push_back(a[i-1]+a[i+1]);
    }
    ans.push_back(a[n-2]);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;*/
}
