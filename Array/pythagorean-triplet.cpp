/*
A program that returns true if there is a Pythagorean Triplet in a given array.
*/

 
#include <iostream>
#include <algorithm>
using namespace std;

bool isTriplet(int arr[], int n)
{
   
    for (int i=0; i<n; i++)
        arr[i] = arr[i]*arr[i];
        
    sort(arr, arr + n);

   
    for (int i = n-1; i >= 2; i--)
    {
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        int l = 0; // index of the first element in arr[0..i-1]
        int r = i-1; // index of the last element in arr[0..i-1]
        while (l < r){
            if (arr[l] + arr[r] == arr[i])
                return true;
            (arr[l] + arr[r] < arr[i])?  l++: r--;
        }
    }
    return false;
}


int main()
{
     int t,n;
    int arr[100001];
    bool a;
    cin>>t;
    while(t--)
    {   cin>>n;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        a=isTriplet(arr, n);
        if(a==true)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;

}
