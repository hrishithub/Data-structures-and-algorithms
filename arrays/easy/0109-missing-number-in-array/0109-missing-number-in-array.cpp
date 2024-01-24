/*
 https://leetcode.com/problems/missing-number/
 Brute: Use nested for loop TC- O(N^2)
 Better: Use hashing (el with freq has zero in hashmap is our ans) TC- O(N) SC-O(N) as we use hashmap
 Optimal: TC- O(N) SC- O(1)
 1) Math approach: Using formula to calculate sum of first N natural numbers (slightly space consuming than approach 2 as we use long)
 2) XOR approach:  This works because of property of XOR which is A^A=0
 */
#include <bits/stdc++.h>
using namespace std;

int missingNumberMaths(vector<int>&a, int N) {

    long totalSum= (N*(N+1))>>1; //Sum of first N natural numbers
    long sum=0;
    for(int i : a) sum+=i; //Sum of all el in array
    return totalSum-sum;

}

int missingNumberXOR(vector<int>&a, int N) {
    int XOR1=0,XOR2=0;
    for (int i = 0; i < N-1; i++) {
        XOR1=XOR1^a[i];
        XOR2=XOR2^(i+1);
    }
    XOR2=XOR2^N;

    return XOR1^XOR2;

}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumberXOR(a, N);
    cout << "The missing number using XOR approach is: " << ans << endl;
    ans= missingNumberMaths(a,N);
    cout << "The missing number using Maths approach is: " << ans << endl;
    return 0;
}
