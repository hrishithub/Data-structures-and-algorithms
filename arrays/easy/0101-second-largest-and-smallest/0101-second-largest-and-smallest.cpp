/*
https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf 
Brute: Sort array and then starting from last return el that doesnt match el n-1th index TC- O(NlogN+N)

Better: Run for loop to find largest and then another for loop to find second largest TC- O(2N)

Optimal: Using single for loop (𝐅𝐢𝐫𝐬𝐭 𝐚𝐬𝐬𝐮𝐦𝐞 𝐞𝐥𝐞𝐦𝐞𝐧𝐭 𝐚𝐭 𝟎𝐭𝐡 𝐢𝐧𝐝𝐞𝐱 𝐚𝐬 𝐥𝐚𝐫𝐠𝐞𝐬𝐭 𝐚𝐧𝐝 𝐰𝐡𝐢𝐥𝐞 𝐥𝐨𝐨𝐩𝐢𝐧𝐠 𝐰𝐡𝐞𝐧 𝐲𝐨𝐮 𝐟𝐢𝐧𝐝 𝐞𝐥𝐞𝐦𝐞𝐧𝐭 𝐠𝐫𝐞𝐚𝐭𝐞𝐫 𝐭𝐡𝐚𝐧 𝐥𝐚𝐫𝐠𝐞𝐬𝐭 𝐭𝐡𝐞𝐧 𝐭𝐡𝐚𝐭 𝐥𝐚𝐫𝐠𝐞𝐬𝐭 𝐢𝐬 𝐧𝐨𝐰 𝐬𝐞𝐜𝐨𝐧𝐝𝐋𝐚𝐫𝐠𝐞𝐬𝐭 𝐚𝐧𝐝  𝐧𝐞𝐰𝐥𝐲 𝐟𝐨𝐮𝐧𝐝 𝐞𝐥𝐞𝐦𝐞𝐧𝐭 𝐢𝐬 𝐧𝐨𝐰 𝐥𝐚𝐫𝐠𝐞𝐬𝐭) TC- O(N) SC- O(1)
*/

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

