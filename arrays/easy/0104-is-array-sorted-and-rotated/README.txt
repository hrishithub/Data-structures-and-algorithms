Check if Array Is Sorted and Rotated

Problem Statement: 
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/#:~:text=Input%3A%20nums%20%3D%20%5B2%2C,no%20rotation)%20to%20make%20nums.

𝐈𝐧 𝐬𝐨𝐫𝐭𝐞𝐝 𝐫𝐨𝐫𝐚𝐭𝐞𝐝 𝐚𝐫𝐫𝐚𝐲 𝐭𝐡𝐞𝐫𝐞 𝐰𝐢𝐥𝐥 𝐛𝐞 𝐨𝐧𝐞 𝐩𝐚𝐢𝐫 𝐨𝐧𝐥𝐲 𝐰𝐡𝐞𝐫𝐞 𝐚𝐫𝐫[𝐢]>𝐚𝐫𝐫[(𝐢+𝟏)%𝐧] 
𝐄𝐝𝐠𝐞 𝐜𝐚𝐬𝐞 - 𝐈𝐧 𝐚𝐫𝐫𝐚𝐲 𝐰𝐡𝐞𝐫𝐞 𝐚𝐥𝐥 𝐞𝐥𝐞𝐦𝐞𝐧𝐭𝐬 𝐚𝐫𝐞 𝐬𝐚𝐦𝐞 𝐭𝐡𝐞𝐫𝐞 𝐰𝐢𝐥𝐥 𝐛𝐞 𝐧𝐨 𝐬𝐮𝐜𝐡 𝐩𝐚𝐢𝐫 𝐬𝐨 𝐢𝐧 𝐭𝐡𝐚𝐭 𝐜𝐚𝐬𝐞 𝐜𝐨𝐮𝐧𝐭 𝐰𝐢𝐥𝐥 𝐛𝐞 𝐳𝐞𝐫𝐨 
𝐬𝐨 𝐫𝐞𝐭𝐮𝐫𝐧 𝐜𝐨𝐮𝐧𝐭<=𝟏
 
Brute Force: 
Time Complexity: O(N^2)
Space Complexity: O(1)

Optimal: 
Edge 
Time Complexity: O(N)
Space Complexity: O(1)
