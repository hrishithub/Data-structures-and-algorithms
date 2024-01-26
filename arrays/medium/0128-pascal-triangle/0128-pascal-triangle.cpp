/*
https://leetcode.com/problems/pascals-triangle/
Explanation of Brute, Better & Optimal approach is provided in pdf
*/
#include<bits/stdc++.h>
using namespace std;

int findCombination(int n, int r) {
    int res=1;
   // (10/1)*(9/2)*(8/3) --> 3 times i.e r times so for loop is running r times
    for (int i = 0; i < r; i++) {
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
} 

//Find element at (row,col) index
int elementInPascalTriangle(int r,int c){
    int ans= findCombination(r-1,c-1);
    cout<<"Element at "<<r<<"th row and "<<c<<"th col is "<<ans<<endl;
}

//Print Nth row of Pascal triangle
int rowInPascalTriangleBrute(int row){
    cout<<row<<"th row in Pascal triangle using approach "<<endl;
    cout<<"1 ";
    for (int i = 1; i <=row; ++i) {
        cout<<findCombination(row-1,i)<<" ";
    } 
    cout<<endl;

    return 0;
}

//Print Nth row of Pascal triangle
int rowInPascalTriangleOptimal(int row){
    cout<<endl;
    int ans=1;
    cout<<ans<<" ";
    for (int col = 1; col <row ; col++) {
        ans=ans*(row-col);
        ans=ans/col;
        cout<<ans<<" ";
    }
    cout<<endl;

}

//Print entire Pascal triangle
int pascalTriangle(int n){
    for(int i=1;i<=n;i++){
        rowInPascalTriangleOptimal(i);
    }
}

int main(){
   int row=6,col=3;
    //1)Find element at (row,col) index
    elementInPascalTriangle(row,col);
     cout<<endl;
    //2)Print Nth row of Pascal triangle
     cout<<row<<"th row in Pascal triangle  ";
    rowInPascalTriangleOptimal(row);
     cout<<endl;
    //3)Print entire Pascal triangle
     cout<<"Pascal triangle with N= "<<row;
    pascalTriangle(row);
}