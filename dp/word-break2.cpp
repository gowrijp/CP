/*
https://www.interviewbit.com/problems/word-break-ii/

Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.
Output Format:

Return a vector of strings representing the answer as described in the problem statement.
Constraints:

1 <= len(A) <= 50
1 <= len(B) <= 25
1 <= len(B[i]) <= 20
Examples:

Input 1:
    A = "b"
    B = ["aabbb"]

Output 1:
    []

Input 1:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]

Output 1:
    ["cat sand dog", "cats and dog"]
*/

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    vector< vector<string> > dp(A.length());
    vector<string> B_new;
    sort(B.begin(),B.end());
    for(int i=0;i<B.size();i++)if(i==0 || B[i]!=B[i-1])B_new.push_back(B[i]);
    B=B_new;
    for(int i=0;i<A.length();i++){
        for(int j=0;j<B.size();j++){
            if((B[j].length() <= (i+1)) && (A.substr(i-B[j].length()+1,B[j].length()) == B[j])){
                if((i+1)==B[j].length())dp[i].push_back(B[j]);
                else{
                    for(int k=0;k<dp[i-B[j].length()].size();k++)dp[i].push_back(dp[i-B[j].length()][k] + " " + B[j]);
                }
            }
        }
    }
    sort(dp[A.length()-1].begin(),dp[A.length()-1].end());
    return dp[A.length()-1];
}
