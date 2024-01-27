/*
Given an integer array, find a subarray that has the largest product, and return the product.
https://leetcode.com/problems/maximum-product-subarray/
Brute: Nested for loops find all possible subarray and consider max product subarray among those all TC-O(N^2) SC-O(1)
Optimal:
Observations - 1) when array contain all positive -> just multiply all that will be max product subarray
               2) when array contains even no. of -ve -> just multiply all that will be max product subarray
               3) when array contains odd no. of -ve -> Removal of 1 -ve out of add no. of -ves will leave us with even no. of
               -ves, hence idea is to remove 1 -ve, sow e now see which 1 -ve to remove, and on removal how is array shaped
               arr[]= [3,2,-1,4,-6,3,-2,6]
               if we remove -1 then we left with prefix-[3,2] and suffix-[4,-6,3,-2,6] -->max(3,864)
               if we remove -6 then we left with prefix-[3,2,-1,4] and suffix-[3,-2,6]  won't work as bot subarray contain 1 -ve
               if we remove -2 then we left with prefix-[3,2,-1,4,-6,3] and suffix-[6] -->max(432,6)
               max(864,432) = 864
               so  maxi=max(maxi,max(prefixMul,suffixMul))
               so we'll take prefix mul and suffix mul and then max(prefix,suffix) and then  maxi=max(maxi,max(prefixMul,suffixMul))
               4) when array contain zero -> [2,3,4,0,6,3,0,2,1] No point in carry forwarding zero as zero*anything is zero so
               [2,3,4] [6,3] [2,1]
               prefixMul is 2*3*4=24 now 0 comes so store 24 in variable now prefixMul is 1 1*6*3..

               Dry runc- [2,3,-2,4]
               maxi= INT_MIN->4->6
               prefixMul=1->2->6->-12->-48
               suffixMUl=1->4->-8->-24->-48
               maxi=max(maxi,max(prefixMul,suffixMul))

               at the end prefixMul==suffixMul
*/

#include<bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &arr){
    int prefixMul=1, suffixMul=1, n=arr.size(), maxi=INT_MIN;

    for (int i = 0; i < n; ++i) {
        //Handling zero edge case when prefixMul or suffixMul become 0 then no point in carry forwarding zero as zero*anything is zero
        if(prefixMul==0) prefixMul=1;
        if(suffixMul==0) suffixMul=1;

        //calculate prefix multiplication
        prefixMul= prefixMul*arr[i];

        //calculate suffix multiplication
        suffixMul= suffixMul* arr[n-i-1];

        //storing maximum product
        maxi=max(maxi,max(prefixMul,suffixMul));
    }
    return maxi;
}
int main(){
    vector<int> arr={3,2,-1,4,-6,3,-2,6};
    cout<<"Maximum product subarray is "<< maxProductSubarray(arr);
    return 0;
}

