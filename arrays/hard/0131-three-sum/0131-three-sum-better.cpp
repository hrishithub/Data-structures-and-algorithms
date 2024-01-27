/*
a[i]+a[j]+a[k]=0
https://leetcode.com/problems/3sum/
Brute: Using three nested for loops
Time Complexity: O(N^3 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.

Better: We are avoiding one extra for loop by //a[i]+a[j]+a[k]=0 which means arr[i]+arr[j]= - a[k] so TC N^3 --> N^2
Time Complexity: O(N^2 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 2 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) hashset for storing the array elements in another set.
How we are making sure we are returning unique triplets?
When we find triplet (such that a[i]+a[j]+a[k]=0) we sort it and then store it in set
Why sort - [-1,-1,2] and [-1,2,-1] are same triplets but set will consider them as different and store separately so after sort both will become [-1,-1,2] now when will try to store set will consider them as same

*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
//    vector<vector<int>> ans;
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset; //We are avoiding one extra for loop by //a[i]+a[j]+a[k]=0 which means arr[i]+arr[j]= - a[k] so TC N^3 --> N^2
        //we are doing arr[i]+arr[j] and finding - a[k] in array if its their then we found triplet and if we put array el in hashset and find then that search op is of constant time
        for (int j = i+1; j < n; ++j) {   //a[i]+a[j]+a[k]=0 which means arr[i]+arr[j]= - a[k]
            int k= -(arr[i]+arr[j]);
            if(hashset.find(k)!=hashset.end()){
                vector<int> temp={arr[i],arr[j],k};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    //now set contains all unique triplets now put them in vector<vector<int>> ans ans return ans
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
