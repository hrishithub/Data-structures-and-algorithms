/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
Brute: Use nested for loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions TC-O(N^2) SC-O(N)
Optimal: To get max profit by selling a stock on ith day we need to buy it at min price from 0th to (i-1)th day
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
   int mini=arr[0],maxProfit=INT_MIN;

    for (int i = 1; i < arr.size(); ++i) {
        int costOfSelling= arr[i]-mini;  //cost of selling stock on ith day if we bought it at min price from 0th to (i-1)th day
        maxProfit=max(maxProfit,costOfSelling);
        mini=min(mini,arr[i]); //update mini
    }

    if(maxProfit<0) return 0;
    return maxProfit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
