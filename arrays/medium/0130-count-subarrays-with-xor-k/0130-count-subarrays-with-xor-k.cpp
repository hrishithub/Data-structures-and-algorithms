/*
https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
Exact similar concept as count subarrays with sum K
Brute: Run nested for loops and check all possible subarrays for XOR K TC-O(N^2) SC-O(1)
Optimal:
Suppose XR is prefix XOR (till i). For ith element to be the last element of a subarray with XOR K there need someone from start with XOR X
X^K=XR
(X^K)^K=XR^K
X=XR^K
*/
#include <bits/stdc++.h>
using namespace std;
//See dry run below!
int subarraysWithXorK(vector<int> a, int k) {
    int n= a.size(); //size of array
    map<int,int> mpp;
    mpp[0]=1;
    int preXOR=0,cnt=0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i
        preXOR^=a[i];

        //By formula: x = xr^k: as discussed above
        int X= preXOR^k;

        //if someone from start have xor of X then it exist in map and its count will get added and if not exist in map then cnt+=0
        cnt+=mpp[X];

        mpp[preXOR]++;
    }
    return cnt;
}

int main()
{
    vector<int> a = {1, 2, 3, 2};
    int k = 2;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}


/*
    arr= [1, 2, 3, 2]   k=2

    | 2->1 |  cnt=1=2=3      2^2=0 in map       //two new subarray (in total 3) found with xor k which is element 2 at 3rd index alone and [1,2,3,2] as 1^2^3^2=2
    | 0->2 |                 0^2=2 not in map
    | 3->1 |  cnt=0+1=1      3^2=1 in map       //one subarray found with xor k which is element 2 at 1st index alone as a subarray
    | 1->1 |                 1^2=3 not in map
    | 0->1 |
    |______|
*/