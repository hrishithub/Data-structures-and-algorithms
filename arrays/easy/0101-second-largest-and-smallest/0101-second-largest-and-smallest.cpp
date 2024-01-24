#include<bits/stdc++.h>
using namespace std;
int secondLargest(int arr[],int n)
{
    if(n<2) return -1; //In this case there will be no second-largest element
    int largest = arr[0];
    int secondLargest = INT_MIN;
    for (int i = 1; i < n; ++i) {
        if(arr[i]>largest){
            secondLargest= largest;
            largest= arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondLargest){
            secondLargest= arr[i];
        }
    }
    return secondLargest;
}
int secondSmallest(int arr[],int n)
{
    if(n<2) return -1; //In this case there will be no second-smallest element
    int smallest = arr[0];
    int secondSmallest = INT_MAX;
    for (int i = 1; i < n; ++i) {
        if(arr[i]<smallest){
            secondSmallest= smallest;
            smallest= arr[i];
        }
        else if(arr[i]>smallest && arr[i]<secondSmallest){
            secondSmallest= arr[i];
        }

    }
    return secondSmallest;
}

int main() {
    int arr[]={1,2,4,7,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sL=secondLargest(arr,n);
    int sS=secondSmallest(arr,n);
    cout<<"Second largest is "<<sL<<endl;
    cout<<"Second smallest is "<<sS<<endl;
    return 0;
}

