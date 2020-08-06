/*
https://www.interviewbit.com/problems/longest-valid-parentheses/
SOLUTION using stacks 
*/
int Solution::longestValidParentheses(string A) {
    int n = A.length();
    if(n<=1)
        return 0;
    stack<int> indices;
    indices.push(-1);
    int last = -1;
    int res = 0;
    for(int i = 0; i<n; i++){
        if(A[i]=='(')
            indices.push(i);
        else{
            int y = indices.top();
            if(y==last){
                last = i;
                indices.push(i);
            }
            else{
                indices.pop();
                y = indices.top();
                res = max(res, i-y);
            }
        }
    }
    return res;
}
