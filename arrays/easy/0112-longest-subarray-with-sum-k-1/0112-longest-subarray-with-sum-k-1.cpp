/*
Brute: Run nested for loops and check all possible subarrays for sum k TC-O(N^2) SC-O(1)

Better: This approach is optimal when array contains positives,negatives and zeroes
Time complexity - O(N+NlogN) where NlogN is time to search in map which will be 1 if we use unordered_map but it can also be N^2 (which is very rare) in WC
This is because ordered map are implemented using red black trees while unordered_map are implemented using hashing so wc occur when collision freq become high so requires time to resolve it
Space complexity- In wc O(N)

Optimal: Sliding Window approach(Optimal when array contain only positives and zeroes)
 */

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
If prefix sum till ith el is X then,
for ith el to be the last el of subarray whose sum is K there need someone from start whose prefix sum is X-K
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(),maxLen=0; // size of the array.
    long long sum=0;
    map<long, long> preSum;

    for (int i = 0; i < n; i++) {
        sum+=a[i]; //Calculating sum till index i

        if(sum==k) { //This is to check whether sum is k or not from starting in the beginning
            maxLen=max(maxLen,i+1);
            continue;
        }

        long long rem=sum-k;

        if(preSum.find(rem)!=preSum.end()){
            //there is someone from start whose prefix sum is X-K
            int length= i-preSum[rem];
            maxLen=max(maxLen,length);
        }

        //when array contains zero  , run algo for this input [2,0,0,0,3].
        //we won't update an el if its already in map as we want the longest subarray
        if(preSum.find(sum)!= preSum.end())
           preSum[sum]=i;
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

