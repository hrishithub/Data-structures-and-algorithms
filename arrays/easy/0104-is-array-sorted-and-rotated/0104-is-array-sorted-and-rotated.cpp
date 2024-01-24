#include<bits/stdc++.h>
using namespace std;

bool isSortedRotated(int arr[], int n) {
    int count=0;
    for (int i = 0; i < n; i++)
        if(arr[i]>arr[(i+1)%n]) count++;
    return count<=1;
}

int main() {
    int arr[] = {1,2,3,4,5}, n = 5;
    cout<<isSortedRotated(arr,n);
}
