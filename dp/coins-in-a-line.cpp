/*
VIDEO SOLUTION : https://youtu.be/WRXCwgdni90

https://www.interviewbit.com/problems/coins-in-a-line/
There are A coins (Assume A is even) in a line.

Two players take turns to take a coin from one of the ends of the line until there are no more coins left.

The player with the larger amount of money wins, Assume that you go first.

Return the maximum amount of money you can win.

NOTE:

You can assume that opponent is clever and plays optimally.

SOLUTION
Bottom up Dp Approach
Lets say some i to j part of the array is under consideration
Then for me there are two options
I choose        He choose       My next available options
i               i+1             f(i+2,j)
                j               f(i+1,j-1)
j               i               f(i+1,j-1)
                j-1             f(i,j-2)

But then my opponent will also optimise and make his choice in such a way that my next available option would be min of the two options left.
So I should choose max(i+min(f(i+2,j),f(i+1,j-1)), j+min(f(i+1,j-1),f(i,j-2)))

This is the recursion

Now to do this using dp we can create a table[n][n]
in cases when i>j fill the table value with 0 
in cases when i=j fill it with ith value from the original array
for rest of the table find using above formula(iteration)

For eg : arr={8,15,3,7}
table will look like this
8  15  11  22
0  15  15  18
0  0   3   7
0  0   0   7

our ans is table[0][n-1]
*/

int Solution::maxcoin(vector<int> &arr) {
    
    int n = arr.size();
    int table[n][n], gap, i, j, x, y, z;
 
    for (gap = 0; gap < n; ++gap)
    {
        for (i = 0, j = gap; j < n; ++i, ++j)
        {
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive formula
            x = ((i+2) <= j) ? table[i+2][j] : 0;
            y = ((i+1) <= (j-1)) ? table[i+1][j-1] : 0;
            z = (i <= (j-2))? table[i][j-2]: 0;
 
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
 
    return table[0][n-1];
}
