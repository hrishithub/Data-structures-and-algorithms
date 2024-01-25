/*
Given an array, print all the elements which are leaders. A Leader is an element that is greater than all the elements on its right side in the array.
Brute: Use nested for loop, for an element run inner for loop to check whether there is element in array at right side of it which is greater than it if there isn't than that element is leader TC-O(N^2) SC-O(N) to return ans
Optimal: using single for loop TC-O(N) SC-O(N) to return ans
when array is in dec order than everyone in array is leader
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

    vector<int> ans;

    // Last element of an array is always a leader, cause there is no element at right to it which is greater than it
    // push into ans array.
    int max = arr[n - 1];
    ans.push_back(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max){
            ans.push_back(arr[i]);
            max=arr[i];
        }
       // else ans.push_back(max); We just have to return elements that are leaders
    }
    return ans;
}

int main() {

    // Array Initialization.
    int n = 6;
    int arr[] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeaders(arr,n);


    for(int i = ans.size()-1;i>=0;i--){

        cout<<ans[i]<<" ";
    }

    cout<<endl;
    return 0;
}
