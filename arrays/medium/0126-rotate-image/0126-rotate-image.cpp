/*
https://leetcode.com/problems/rotate-image/
Brute: Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so. TC-O(N*M) SC- O(N*M)
Optimal: Take transpose of a matrix and then reverse each row in transposed matrix TC-O(2N*M) SC-O(1)
*/
#include<bits/stdc++.h>
using namespace std;

void Reverse(vector < int >& arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(vector < vector < int >> & matrix) {
    int n= matrix.size();
    int m= matrix[0].size();
    //Transpose of a matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            //swap matrix[i][j] with matrix[j][i]
            int temp= matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }

    //Reverse each row of transposed matrix
    for (int i = 0; i < n; i++){
        Reverse(matrix[i],0,m-1);
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}
