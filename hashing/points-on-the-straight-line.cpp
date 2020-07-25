/*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
Sample Input :
(1, 1)
(2, 2)
Sample Output : 2
You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])
eg:
X:1,3,2,3,6,4
Y:1,4,2,3,7,4
ans:4

Base case: n<=2 return n
first check coincident points-[over]-(same x and same y) and get the count
then check for vertical lines[ver]-, i.e. same x and get count
then use a map to get slopes[cur]- and count of points with same slope corrresponding to each i
for each i calculate ans at every iteration
ans = max(ans,ver+over+1)
ans = max(ans,cur+over+1)
*/

#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<int> &A, vector<int> &B) 
{
    if(A.size()<3)
        return A.size();                    //Y:1,4,2,3,7,4
    unordered_map<double,int> sl;           //X:1,3,2,3,6,4
    int n=A.size(),cur,ver,over,ans=0;      //n=6
    double m;                               
    for(int i=0;i<n-1;i++)
    {
        cur=ver=over=0;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]==A[i])
            {
                if(B[j]==B[i])
                over++;             //i.e if two points are same(coincident)
                else
                ver++;              //two points have same x(i.e. lie on a vertical line)
            }
            else
            {
                m=(double)(B[j]-B[i])/(double)(A[j]-A[i]);  //calculating slope
                sl[m]++;
                cur=max(cur,sl[m]);                         //getting the slope value with max pair of points
            }
        }
        sl.clear();
        ans=max(ans,ver+over+1);
        ans=max(ans,cur+over+1);
    }
    return ans;
}

int main(){
    vector<int> A= {1,3,2,3,6,4};
    vector<int> B = {1,4,2,3,7,4};
    cout<<maxPoints(A,B)<<endl;
}