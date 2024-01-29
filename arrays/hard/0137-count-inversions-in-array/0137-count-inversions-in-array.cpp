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
        else{ 
             temp.push_back(arr[right++]);
             cnt+=(mid-left+1);  
            }
    } 

    //If we come here means any one of the pointer either left or right goes out of bound 

    while(left<=mid){
        temp.push_back(arr[left++]);
    }

    while(right<=high){ 
    /*
    Here right is smaller too but we dont write cnt+=(mid-left+1) here because logic we are using on 2 sorted arrays to count inversion pair in that when any
    of the pointer either left or right goes out of bound then we stop cause now we aren't going to get a inversion pair {arr[left],arr[right]} such that arr[left]>arr[right] as one of the pointer in exceeded so how can you do comparison of arr[left] and arr[right]
    */
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

    cout<<"Count of inversion pairs in given array is "<<  mergeSort(arr, 0, n - 1); 

    return 0 ;
}

