/*
https://www.interviewbit.com/problems/reverse-bits/
Input 1:  0
Input 2:  3

Output 1:  0
Output 2:  3221225472

Explanation 1:
        00000000000000000000000000000000

=>      00000000000000000000000000000000
Explanation 2:
        00000000000000000000000000000011    
=>      11000000000000000000000000000000
*/

unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans=0;
    vector<int> binary;
    int i=0;
    if(A==0)
        return 0;
    while(A!=0){
        i++;
        binary.insert(binary.begin(),A%2);
        A/=2;
    }
    
    while(i!=32){
        binary.insert(binary.begin(),0);
        i++;
    }
    for(int i=31;i>=0;i--){
        ans+=(binary[i]*pow(2,i));
    }
    return ans;
}
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Alternate solution
unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans=0;
    for(int i=0;i<32;i++){
        ans+=(A&1)<<(31-i);
        A>>=1;
    }
    return ans;
}
