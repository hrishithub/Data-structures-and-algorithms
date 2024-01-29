/*
Explanation with dry run is written in notebook
*/

#include<bits/stdc++.h>
using namespace std;

int countReversePairs(vector<int> &arr,int low, int mid, int high){
    int right=mid+1, cnt=0;

    for (int i = low; i <=mid; i++) {
        while(right<= high && arr[i] > (long) (2L*arr[right])){right++ ;} //to avoid runtime error: signed integer overflow: 2 * 2147483647 cannot be represented in type 'int' when input is [2147483647,2147483647,2147483647,2147483647,2147483647,2147483647]
        //Adding the L suffix makes the constant 2 a long, and the multiplication will be performed using long arithmetic, avoiding the overflow issue.
        //we came of loop so unmatched so count no. of elements before unmatched element as those many no. of elements can form par with arr[i]
        cnt+=(right-(mid+1));
    }
    return cnt;
}

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

int mergeSort(vector<int> &arr, int low, int high) {

    int cnt=0;

    //Base case of recursion
    if(low==high) return cnt;

    int mid= (low+high)/2;

    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    //count reverse pairs before performing merge operation
    cnt+= countReversePairs(arr,low,mid,high);
    merge(arr,low,mid,high);

    return cnt;
}

int main() {

    vector<int> arr = {4,1,2,3,1}  ;
    int n = 5;

    cout<<"Count of reverse pairs in given array is "<<  mergeSort(arr, 0, n - 1);
    return 0 ;
}

