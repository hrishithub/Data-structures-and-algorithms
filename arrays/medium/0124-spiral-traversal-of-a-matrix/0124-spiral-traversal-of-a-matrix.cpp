/*
https://leetcode.com/problems/spiral-matrix/
There is no brute force approach for it this problem is asked in interview to check your implementation skills and clean code writing.
TC- O(N*M) SC- Extra space is used to store and return the answer

   l   r
t  x x x
   x x x
b  x x x

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>>& matrix){
    vector<int> ans;
    int n= matrix.size();
    int m= matrix[0].size();

    //Initialize top bottom left and right variable
    int top=0, bottom=n-1, left=0, right=m-1;


   while(left<=right && top<=bottom){

       //loop to print top
       //since we're printing top before running this for loop in beginning while condition have checked that top<=bottom
       for (int i = left; i <= right; i++) {
           ans.push_back(matrix[top][i]);
       }
       top++;

       //loop to print right
       //since we're printing right before running this for loop in beginning while condition have checked that left<=right
       for (int i = top; i <= bottom; i++) {
           ans.push_back(matrix[i][right]);
       }
       right--;

       //since after running above two for loop we upgrade top and right it might be possible that now top>bottom or left>right so while checks in beginning aren't true now
       //so for below two for loops apply checks before printing

       //loop to print bottom
       //since we're printing bottom check top<=bottom still holds true than only print it
       if(top<=bottom){
           for (int i = right; i >= left; i--) {
               ans.push_back(matrix[bottom][i]);
           }
           bottom--;
       }


       //loop to print left
       //since we're printing left check left<=right still holds true than only print it
       if(left<=right){
           for (int i = bottom; i >= top; i--) {
               ans.push_back(matrix[i][left]);
           }
           left++;
       }

   }

    return ans;


   //Edge case in case of only single row is given only first for loop will get print after that top will exceed bottom so rest three for loops won't run

}
int main() {

    //Matrix initialization.
    vector<vector<int>> matrix   {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    vector<int> ans = printSpiral(matrix);

    for(int i = 0;i<ans.size();i++){

        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return 0;
}