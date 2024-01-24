/* 
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/#:~:text=Input%3A%20nums%20%3D%20%5B2%2C,no%20rotation)%20to%20make%20nums.
𝐈𝐧 𝐬𝐨𝐫𝐭𝐞𝐝 𝐫𝐨𝐭𝐚𝐭𝐞𝐝 𝐚𝐫𝐫𝐚𝐲 𝐭𝐡𝐞𝐫𝐞 𝐰𝐢𝐥𝐥 𝐛𝐞 𝐨𝐧𝐞 𝐩𝐚𝐢𝐫 𝐨𝐧𝐥𝐲 𝐰𝐡𝐞𝐫𝐞 𝐚𝐫𝐫[𝐢]>𝐚𝐫𝐫[(𝐢+𝟏)%𝐧] 
𝐄𝐝𝐠𝐞 𝐜𝐚𝐬𝐞 - 𝐈𝐧 𝐚𝐫𝐫𝐚𝐲 𝐰𝐡𝐞𝐫𝐞 𝐚𝐥𝐥 𝐞𝐥𝐞𝐦𝐞𝐧𝐭𝐬 𝐚𝐫𝐞 𝐬𝐚𝐦𝐞 𝐭𝐡𝐞𝐫𝐞 𝐰𝐢𝐥𝐥 𝐛𝐞 𝐧𝐨 𝐬𝐮𝐜𝐡 𝐩𝐚𝐢𝐫 𝐬𝐨 𝐢𝐧 𝐭𝐡𝐚𝐭 𝐜𝐚𝐬𝐞 𝐜𝐨𝐮𝐧𝐭 𝐰𝐢𝐥𝐥 𝐛𝐞 𝐳𝐞𝐫𝐨 
𝐬𝐨 𝐫𝐞𝐭𝐮𝐫𝐧 𝐜𝐨𝐮𝐧𝐭<=𝟏
 
Brute Force: 
Time Complexity: O(N^2)
Space Complexity: O(1)

Optimal: 
Edge 
Time Complexity: O(N)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

bool isSortedRotated(int arr[], int n) {
    int count=0;
    for (int i = 0; i < n; i++)
        if(arr[i]>arr[(i+1)%n]) count++;
    return count<=1;
}

int main() {
    int arr[] = {1,2,3,4,5}, n = 5;
    cout<<isSortedRotated(arr,n);
}
