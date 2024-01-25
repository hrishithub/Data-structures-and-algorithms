/*
https://leetcode.com/problems/rearrange-array-elements-by-sign/
Brute: Using pos[] and neg[] array TC-O(1.5N) SC-O(N)
Optimal: Using ans[] array TC- O(N) SC-O(N)
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangeBySign(vector<int>& A){
    vector<int> ans(A.size());
    int posIndex=0,negIndex=1;
    for (int i = 0; i < A.size(); i++) {
        if(A[i]>0) {
            ans[posIndex] = A[i];
            posIndex+=2;
        }
        else{
            ans[negIndex]=A[i];
            negIndex+=2;
        }
    }
    return ans;
    }




int main() {

    // Array Initialisation.

    vector<int> A = {3,1,-2,-5,2,-4};

    vector<int> ans = RearrangeBySign(A);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}