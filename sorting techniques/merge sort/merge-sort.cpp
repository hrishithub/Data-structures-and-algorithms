/*
Merge Sort is a divide and conquers algorithm, it divides the given array into equal parts and then merges the 2 sorted parts.
Explantaion with dry run is written in notebook.
Time complexity: O(nlogn) 
Reason: At each step, we divide the whole array, for that logn and we assume n steps are taken to get sorted array, so overall time complexity will be nlogn

Space complexity: O(n)  
Reason: We are using a temporary array to store elements in sorted order.

Auxiliary Space Complexity of recursion: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low, int mid, int high){

    vector<int> temp;

    int left=low;    //pointer on left subarray
    int right=mid+1; //pointer on right subarray


    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }

    while(left<=mid){
        temp.push_back(arr[left++]);
    }

    while(right<=high){
        temp.push_back(arr[right++]);
    }

    //Copy elements in temp array into original arr array
    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }

}

void mergeSort(vector<int> &arr, int low, int high) {

    //Base case of recursion
    if(low==high) return;

    int mid= (low+high)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}

