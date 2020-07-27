/*You are given an array of N integers, A1, A2 ,..., AN and an integer B. 
Return the of count of distinct numbers in all windows of size B.
Formally, return an array of size N-B+1 where i'th element in this array 
contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE: if B > N, return an empty array.

Input Format
First argument is an integer array A
Second argument is an integer B.

Output Format
Return an integer array.

Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3                          Output : [2, 3, 3, 2]
Input 2:

 A = [1, 1, 2, 2]
 B = 1                          Output : [1, 1, 1, 1]

Example Explanation
Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].
Explanation 2:

 Window size is 1, so the output array is [1, 1, 1, 1]
 */

vector<int> Solution::dNums(vector<int> &a, int b) {
    vector<int>res;
    int end=0,start=0;
    int n =  a.size();
    assert(b<=n);
    unordered_map<int,int>mp;
    int count=0;
    
    for(end=0;end<n;end++){
        mp[a[end]]++;
        
        if(end-b+1>=0){
            res.push_back(mp.size());
            mp[a[start]]--;
            
            if(mp[a[start]]==0)
                mp.erase(a[start]);
            start++;
        }
    }
    return res;
}
