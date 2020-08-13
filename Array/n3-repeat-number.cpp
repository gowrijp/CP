/*
https://www.interviewbit.com/problems/n3-repeat-number/

General soln for greater than n/k occurances

MOORE'S VOTING ALGORITHM FOR MAJORITY ELEMENT IS USED IN THIS
O(K) EXTRA SPACE
O(N) TIME COMPLEXITY
*/

int Solution::repeatedNumber(const vector<int> &A) {
    int m1=0,m2=0, num1=A[0], num2=A[1];
    for(int i=0; i<A.size(); i++) {
        if(A[i] == num1) m1++;
        else if(A[i] == num2) m2++;
        else if(m1 == 0) {
            num1=A[i];
            m1=1;
        }
        else if(m2 == 0) {
            num2=A[i];
            m2=1;
        }
        else {
            m1--;
            m2--;
        }
    }
    int freq1=0,freq2=0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == num1) freq1++;
        if(A[i] == num2) freq2++;
    }
    if(freq1>(A.size()/3)) return num1;
    if(freq2>(A.size()/3)) return num2;
    return -1;
}

