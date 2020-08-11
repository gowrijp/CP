/*
https://www.interviewbit.com/problems/flip/
*/

vector<int> Solution::flip(string A) {
    int max_so_far = 0;
    int mx1 = -1, mx2 = -1;
    int max_end_here = 0;
    int x1 = 0, x2 = -1;
    for(int i=0;i<A.length();i++){
    	x2++;
    	if(A.at(i)=='1')
    		max_end_here -= 1;
    	else
    		max_end_here += 1;
    	if(max_end_here<0)
    	{
    		max_end_here = 0;
    		x1 = i+1;
    		x2 = i;
    	}
    	if(max_end_here>max_so_far)
    	{
    		max_so_far = max_end_here;
    		mx1 = x1+1;
    		mx2 = x2+1;
    	}
    }
    vector<int> v;
    if(mx1<0 || mx2<0) return v;
    v.push_back(mx1);
    v.push_back(mx2);
    return v;
}
