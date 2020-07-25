/*Determine if a Sudoku is valid.The Sudoku board could be partially filled, where empty 
cells are filled with the character ‘.’. Given is a vector of strings
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

5 3 . . 7 . . . . 
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
*/

#include<bits/stdc++.h>
using namespace std;

int isValidSudoku(const vector<string> &A) {
    bool r[9][9], c[9][9], s[3][3][9];
    memset(r, false, sizeof(r));
    memset(c, false, sizeof(c));
    memset(s, false, sizeof(s));
    int number;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (A[i][j] > '0' && A[i][j] <='9') {
                number = A[i][j] - '1';
                if (r[i][number]) return false;
                r[i][number] = true;
                if (c[j][number]) return false;
                c[j][number] = true;
                if (s[i / 3][j / 3][number]) return false;
                s[i / 3][j / 3][number] = true;
            }
        }
    }
    return true;
    
}
int main(){
    vector<string> sudoku={"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    cout<<isValidSudoku(sudoku)<<"\n";
}