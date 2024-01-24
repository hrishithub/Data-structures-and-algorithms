/*
Optimal: Two pointer/Sliding window approach TC- O(2N) SC- O(1)
Intuition: We are using two pointers i.e. left and right. The left pointer denotes the starting index of the subarray and the right pointer denotes the ending index.
Now as we want the longest subarray, we will move the right pointer in a forward direction every time adding the element i.e. a[right] to the sum.
But when the sum of the subarray crosses k, we will move the left pointer in the forward direction as well to shrink the size of the subarray as well as to decrease the sum.
Thus, we will consider the length of the subarray whenever the sum becomes equal to k.
*/
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    int left=0,right=0, maxLen=0;
    long long sum=a[0];

    while(right<n){
        //when sum > K simply start removing el from left
        while (left<=right && sum > k){
            sum-=a[left++];
        }

        //and when sum==K cal window size
        if(sum == k) maxLen=max(maxLen,right-left+1);

        //This we do only when right<n and sum < K so to reach K
        right++;
        if(right<n) sum+=a[right];
    }

    return maxLen;


}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
 