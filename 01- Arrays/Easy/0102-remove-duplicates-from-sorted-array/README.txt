Remove Duplicates in-place from Sorted Array

Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.
https://leetcode.com/problems/remove-duplicates-from-sorted-array/#:~:text=Input%3A%20nums%20%3D%20%5B0%2C,%2C%203%2C%20and%204%20respectively.

Brute Force: Use Set (First traverse array and put everything in set and then just traverse set and start replacing element taken out from set with elements in array from start). This will work because set contains unique elements. 
TC: O(NlogN + K)
SC: O(K) or O(N) in worst case when given array contains all unique

Optimal: Two Pointer Approach 
TC: O(N)
SC: o(1) 

