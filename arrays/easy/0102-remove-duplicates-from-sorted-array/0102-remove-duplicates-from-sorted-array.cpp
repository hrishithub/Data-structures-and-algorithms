//Brute: Use Set (First traverse array and put everything in set and then just traverse set and start replacing element taken out from set with elements in array from start). This will work because set contains unique elements. TC- O(NlogN+K) SC- O(K)
//Optimal: Two pointer approach TC- O(N) SC- O(1)

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{   int i=0;
    for (int j  = 1;  j< n; j++) {
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    //0102-remove-duplicates-from-sorted-array
    return i+1;
}

int main() {
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
}
