/*
https://leetcode.com/problems/set-matrix-zeroes/
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.You must do it in place.
Brute: First traverse matrix and for every zero mark every non-zero element in its corresponding row and col as -1 , then traverse again and mark all -1s as 0. TC- O((N*M)(N+M) + (N*M)) ~ O(N^3) SC-O(1)
Better: Use row[] and col[], TC-O(2(N*M)) SC-O(N+M)
Optimal:  TC-O(2(N*M)) SC-O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0] //zeroth col for row mark
    // int col[m] = {0}; --> matrix[0][..] //zeroth row for col mark

    int col0=1; //for col mark of elements in zeroth column

    //Step 1: Traverse and mark matrix[..][0](row mark) and matrix[0][..](col mark) for every zero element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            //If element is zero mark its matrix[..][0](row mark) and matrix[0][..](col mark)
            if(matrix[i][j]==0){
                matrix[i][0]=0; //row mark
                if(j!=0)
                matrix[0][j]=0; //col mark
                else col0=0;
            }

        }

    }

    //Step 2: Now traverse and set every of that element as zero whose row mark and col mark is marked as zero
    //Except 0th row and 0th col (from (1,1) to (n-1, m-1)) as will do that at last cause on basis of 0th row and 0th col we are setting others up so setting them up first will cause problem of those who aren't supposed to set will also get set
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            //for an element if its either of row mark(matrix[i][0]) or col mark( matrix[0][j]) is marked as zero then set that element as zero
            if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
        }
    }

    //Step 3: Now set elements in zeroth row
    if(matrix[0][0]==0){
        for (int j = 0; j < m; j++) {
            matrix[0][j]=0;
        }
    }

    //Step 4: Now set elements in zeroth col
    if(col0==0){
        for (int i = 0; i < n; i++) {
            matrix[i][0]=0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n"<<endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
