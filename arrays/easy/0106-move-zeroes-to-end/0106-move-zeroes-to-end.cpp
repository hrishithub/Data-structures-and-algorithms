/*
https://leetcode.com/problems/move-zeroes/
Brute Force:
Suppose, there are N-X zeros and X non-zero elements in the array. We will first copy those X non-zero elements from the original array to a temporary array. 
Then, we will copy the elements from the temporary array one by one and fill the first X places of the original array. 
The last N-X places of the original array will be then filled with zero. Now, our task is completed.

Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
X = no. of non-zero elements, and N-X = total no. of zeros.
Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).
Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be non-zero.

Optimal: 
𝐓𝐰𝐨 𝐩𝐨𝐢𝐧𝐭𝐞𝐫 𝐚𝐩𝐩𝐫𝐨𝐚𝐜𝐡 (𝐅𝐢𝐫𝐬𝐭 𝐤𝐞𝐞𝐩 𝐚 𝐩𝐨𝐢𝐧𝐭𝐞𝐫 𝐚𝐭 𝐟𝐢𝐫𝐬𝐭 𝐳𝐞𝐫𝐨 𝐞𝐥 𝐨𝐟 𝐚𝐫𝐫𝐚𝐲 (𝐧𝐨𝐰 𝐭𝐡𝐚𝐭 𝐩𝐨𝐢𝐧𝐭𝐞𝐫 𝐰𝐢𝐥𝐥 𝐚𝐥𝐰𝐚𝐲𝐬 𝐩𝐨𝐢𝐧𝐭 𝐭𝐨 𝐳𝐞𝐫𝐨 𝐞𝐥) 𝐚𝐧𝐝 𝐬𝐭𝐚𝐫𝐭 𝐚𝐧𝐨𝐭𝐡𝐞𝐫 𝐩𝐨𝐢𝐧𝐭𝐞𝐫 𝐟𝐫𝐨𝐦 𝐧𝐞𝐱𝐭 𝐨𝐟 𝐭𝐡𝐚𝐭 𝐩𝐨𝐢𝐧𝐭𝐞𝐫 𝐰𝐡𝐞𝐧𝐞𝐯𝐞𝐫 𝐚𝐧𝐨𝐭𝐡𝐞𝐫 𝐩𝐨𝐢𝐧𝐭𝐞𝐫 𝐟𝐢𝐧𝐝𝐬 𝐧𝐨𝐧 𝐳𝐞𝐫𝐨 𝐞𝐥 𝐬𝐰𝐚𝐩 𝐢𝐭 𝐰𝐢𝐭𝐡 𝐩𝐨𝐢𝐧𝐭𝐞𝐫 𝐩𝐨𝐢𝐧𝐭𝐢𝐧𝐠 𝐭𝐨 𝐳𝐞𝐫𝐨 𝐞𝐥 𝐚𝐧𝐝 𝐧𝐨𝐰 𝐦𝐨𝐯𝐞 𝐛𝐨𝐭𝐡 𝐩𝐨𝐢𝐛𝐭𝐞𝐫𝐬 𝐟𝐨𝐫𝐰𝐚𝐫𝐝)

Time Complexity: O(N), N = size of the array.
Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int>& a) {
    int i=-1;

    //find first zero el and place i pointer there
    for (int j = 0; j < n; j++)
    {
       if(a[j]==0){
        i=j;
        break;
       }
    } 

    if(i==-1) return a; //In this case array contain all non zero elements

    for (int j = i+1; j < n; j++)
    {
       if(a[j]!=0){
        swap(a[i],a[j]);
        i++;
       }
    } 
    return a;
    
    
    
}


int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
     moveZeros(n, arr);
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
