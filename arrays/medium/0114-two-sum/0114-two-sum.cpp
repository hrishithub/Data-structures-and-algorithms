/*
 https://leetcode.com/problems/two-sum/
 Brute: Use nested for loop TC- O(N^2) SC- O(1)
 Better: Use hashing TC-O(NlogN) (if use ordered map) SC-O(N)
 Optimal: Two pointer approach TC- O(NlogN + N) SC- O(N)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left=0,right=arr.size()-1;

    while(left < right){
        if(arr[left]+arr[right] < target) left++;
        else if(arr[left]+arr[right] > target) right--;
        else return {left,right};
    }
    return {-1,-1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 16;
    vector<int> ans = twoSum(n, arr, target);
    cout << "Element "<<arr[ans[0]]<<" and "<<arr[ans[1]]<<" forms target sum of "<< target<< endl;
    return 0;
}