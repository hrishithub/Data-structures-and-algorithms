/*
 https://leetcode.com/problems/single-number/
 Brute: Use nested for loop TC- O(N^2) SC- O(1)
 Better: Use Hashing (el with freq as one in hashmap is our ans) TC- O(N) SC-O(N) as we use hashmap
 Optimal: XOR approach (This works because of property of XOR which is A^A=0) TC- O(N) SC- O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {
    //size of the array:
    int n = arr.size();
    int XOR=0;
    // XOR all the elements:
    for (int i = 0; i < n; ++i) {
        XOR^=arr[i];
    }
    return XOR;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
