/*
Explantaion with dry run is written in notebook
*/


#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr,int low, int mid, int high){
    int cnt=0;  //variable that counts inversions
    vector<int> temp;

    int left=low;    //pointer on left subarray
    int right=mid+1; //pointer on right subarray


    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        //Inversion pair is arr[left] > arr[right]
        else {
            temp.push_back(arr[right++]);
            if(arr[left] > (2*arr[right]))  cnt+=(mid-left+1);  
           // cnt+=(mid-left+1);  
            }
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

    return cnt;

}

int mergeSort(vector<int> &arr, int low, int high) {
     
    int cnt=0;    //variable that counts inversions   

    //Base case of recursion
    if(low==high) return cnt;

    int mid= (low+high)/2;

    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high); 

    return cnt;

}

int main() {

    vector<int> arr = {4, 1, 2, 3, 1}  ;
    int n = 5;

    cout<<"Count of inversion pairs in given array is "<<   mergeSort(arr, 0, n - 1); 

    return 0 ;
}

