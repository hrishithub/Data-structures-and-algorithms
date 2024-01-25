/*
https://leetcode.com/problems/maximum-subarray/
Brute:Use nested for loops and try out all possible subarray for maximum sum TC-O(N^2) SC-O(1)
Optimal: Kadane's algorithm TC-O(N) SC-O(1)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
There is no point in carry forwarding -ve sum as it will deduce sum only cause if we get next el as -ve then -ve + -ve will more -ve and if we get next el as +ve then adding -ve to it will just deduce it
We will carry forward +ve sum cause there is chance that later on we'll get more +ve, and it'll just enhance sum
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long maxSubarraySum(int v[], int n) {

    long long sum=0, maxSum= INT_MIN;

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        sum+=v[i];
        if(sum < 0) sum=0; //don't carry forward -ve sum
        else  maxSum=max(maxSum,sum); //sum > 0
    }
    return maxSum;

}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}


