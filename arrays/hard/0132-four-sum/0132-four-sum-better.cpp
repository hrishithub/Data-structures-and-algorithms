/*
a[i]+a[j]+a[k]+a[l]=target
https://leetcode.com/problems/4sum/
Same concept as three sum
Brute: Using four nested for loops
Time Complexity: O(N^4 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 4 nested loops. And inserting quadruplets into the set takes O(log(no. of unique quadruplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 4 elements every time.
Space Complexity: O(2 * no. of the unique quadruplets) as we are using a set data structure and a list to store the quadruplets.

Better: We are avoiding one extra for loop by //a[i]+a[j]+a[k]+a[l]=target which means a[i]+a[j]+a[k]=target-a[l] so TC N^4 --> N^3
Time Complexity: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.
Space Complexity: O(2 * no. of the quadruplets)+O(N)
Reason: we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).
How we are making sure we are returning unique quadruplets?
When we find quadruplets (such that a[i]+a[j]+a[k]+a[l]=target) we sort it and then store it in set
Why sort - [-1,-1,2,2] and [-1,2,-1,2] are same quadruplets but set will consider them as different and store separately so after sort both will become [-1,-1,2,2] now when will try to store set will consider them as same

*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

