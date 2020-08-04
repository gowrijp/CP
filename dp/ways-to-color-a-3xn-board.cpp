/*
IMP LINK :: https://medium.com/algorithm-and-datastructure/number-of-ways-to-paint-n-3-grid-170b04213d46

https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
Given a 3 x A board, find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.
Diagonal neighbors are not treated as adjacent boxes.
Return the ways modulo 109 + 7 as the answer grows quickly.

Input 1:
    A = 1

Output 1:
    36

Input 2:
    A = 2

Output 2:
    588
*/

#define lli long long int
#define m 1000000007

int Solution::solve(int A){
    lli x=12,y=24;
    for(int i=2;i<=A;i++){
        lli x_ = (7*x+5*y)%m;
        lli y_ = (10*x+11*y)%m;
        x=x_;
        y=y_;
    }
    return(x+y)%m;
}

