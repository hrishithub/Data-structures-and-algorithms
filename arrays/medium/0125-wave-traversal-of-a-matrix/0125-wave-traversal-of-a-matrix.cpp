/*
https://www.codingninjas.com/studio/problems/print-like-a-wave_893268?leftPanelTabValue=PROBLEM
There is no brute force approach for it this problem is asked in interview to check your implementation skills and clean code writing.
TC- O(N*M) SC- Extra space is used to store and return the answer

   l   r
t  x x x
   x x x
b  x x x

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> printWave(vector<vector<int>> matrix) {
    vector<int> ans;
    int n= matrix.size();
    int m= matrix[0].size();

    //Initialize top bottom left and right variable
    int top=0, bottom=n-1, left=0, right=m-1;

    while(left<=right){
      //print top to bottom
      for (int i = top; i <= bottom ; i++) {
          ans.push_back(matrix[i][left]);
      }
      left++;

      //print bottom to top
      //left might've exceeded right after upgradation after completion of above for loop
      if(left<=right){
          for (int i = bottom; i >= top ; i--) {
              ans.push_back(matrix[i][left]);
          }
          left++;
      }

  }
  return ans;
}




int main() {

    //Matrix initialization.
    vector<vector<int>> matrix   {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    vector<int> ans = printWave(matrix);

    for(int i = 0;i<ans.size();i++){

        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return 0;
}


